#include "so_long.h"

void print_up(t_data *data)
{
    char *res;

    if (all_collected(data) && data->map[data->player_height - 1][data->player_width] != '1' && data->map[data->player_height - 1][data->player_width] == 'E')
    {
        data->moves++;
        write(1, "moves: ", 8);
        res = ft_itoa(data->moves);
        ft_putstr(res);
        write(1, "\nyou won", 8);
        free(res);
        close_window(data);
        exit(0);
    }
    else if (data->map[data->player_height - 1][data->player_width] != '1' && data->map[data->player_height - 1][data->player_width] != 'E')
    {
        up(data);
        data->moves++;
        write(1, "moves: ", 8);
        res = ft_itoa(data->moves);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }
}
void print_down(t_data *data)
{
    char *res;

    if (all_collected(data) && data->map[data->player_height + 1][data->player_width] != '1' && data->map[data->player_height + 1][data->player_width] == 'E')
    {
        data->moves++;
        write(1, "moves: ", 8);
        res = ft_itoa(data->moves);
        ft_putstr(res);
        write(1, "\nyou won", 8);
        free(res);
        close_window(data);
        exit(0);
    }
    else if (data->map[data->player_height + 1][data->player_width] != '1' && data->map[data->player_height + 1][data->player_width] != 'E')
    {
        down(data);
        data->moves++;
        res = ft_itoa(data->moves);
        write(1, "moves: ", 8);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }
}
void print_left(t_data *data)
{
    char *res;

    if (all_collected(data) && data->map[data->player_height][data->player_width - 1] != '1' && data->map[data->player_height][data->player_width - 1] == 'E')
    {
        data->moves++;
        write(1, "moves: ", 8);
        res = ft_itoa(data->moves);
        ft_putstr(res);
        write(1, "\nyou won", 8);
        free(res);
        close_window(data);
        exit(0);
    }
    else if (data->map[data->player_height][data->player_width - 1] != '1' && data->map[data->player_height][data->player_width - 1] != 'E')
    {
        left(data);
        data->moves++;
        res = ft_itoa(data->moves);
        write(1, "moves: ", 8);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }
}
void print_right(t_data *data)
{
    char *res;

    if (all_collected(data) && data->map[data->player_height][data->player_width + 1] != '1' && data->map[data->player_height][data->player_width + 1] == 'E')
    {
        data->moves++;
        write(1, "moves: ", 8);
        res = ft_itoa(data->moves);
        ft_putstr(res);
        write(1, "\nyou won", 8);
        free(res);
        close_window(data);
        exit(0);
    }
    else if (data->map[data->player_height][data->player_width + 1] != '1' && data->map[data->player_height][data->player_width + 1] != 'E')
    {
        right(data);
        data->moves++;
        res = ft_itoa(data->moves);
        write(1, "moves: ", 8);
        ft_putstr(res);
        free(res);
        ft_putstr("\n");
    }
}