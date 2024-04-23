#include "so_long.h"

void print_up(t_data *data)
{
    char *res;

    if (data->map[data->player_height -1][data->player_width] != '1')
    {
        up(data);
        data->moves++;
        res = ft_itoa(data->moves);
        write(1,"moves: ",8);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }   
}
void print_down(t_data *data)
{
    char *res;

    if (data->map[data->player_height +1][data->player_width] != '1')
    {
        down(data);
        data->moves++;
        res = ft_itoa(data->moves);
        write(1,"moves: ",8);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }   
}
void print_left(t_data *data)
{
    char *res;

    if (data->map[data->player_height][data->player_width -1] != '1')
    {
        left(data);
        data->moves++;
        res = ft_itoa(data->moves);
        write(1,"moves: ",8);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }   
}
void print_right(t_data *data)
{
    char *res;

    if (data->map[data->player_height][data->player_width +1] != '1')
    {
        right(data);
        data->moves++;
        res = ft_itoa(data->moves);
        write(1,"moves: ",8);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }
}