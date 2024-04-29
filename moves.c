#include "so_long.h"

void up(t_data *data)

{
    // if (data->map[data->player_height - 1][data->player_width] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    // else
    data->map[data->player_height - 1][data->player_width] = 'P';
    data->map[data->player_height][data->player_width] = '0';
   
}
void down(t_data *data)
{
    //     if (data->map[data->player_height + 1][data->player_width] == '1')
    //         data->map[data->player_height][data->player_width] = 'P';
    data->map[data->player_height + 1][data->player_width] = 'P';
    data->map[data->player_height][data->player_width] = '0';
}
void left(t_data *data)
{
    // if (data->map[data->player_height][data->player_width - 1] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    data->map[data->player_height][data->player_width - 1] = 'P';
    data->map[data->player_height][data->player_width] = '0';
    data->left = 1;
    data->right = 0;

}
void right(t_data *data)
{
    // if (data->map[data->player_height - 1][data->player_width + 1] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    data->map[data->player_height][data->player_width + 1] = 'P';
    data->map[data->player_height][data->player_width] = '0';
    data->left = 0;
    data->right = 1;
}