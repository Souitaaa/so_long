#include "so_long.h"

void up(t_data *data)

{
    // if (data->map[data->player_height - 1][data->player_width] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    // else
    data->map[data->player_height][data->player_width] = '0';
    data->map[data->player_height - 1][data->player_width] = 'P';
}
void down(t_data *data)
{
//     if (data->map[data->player_height + 1][data->player_width] == '1')
//         data->map[data->player_height][data->player_width] = 'P';
    data->map[data->player_height][data->player_width] = '0';
    data->map[data->player_height + 1][data->player_width] = 'P';
}
void left(t_data *data)
{
    // if (data->map[data->player_height][data->player_width - 1] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    data->map[data->player_height][data->player_width] = '0';
    data->map[data->player_height][data->player_width - 1] = 'P';
}
void right(t_data *data)
{
    // if (data->map[data->player_height - 1][data->player_width + 1] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    data->map[data->player_height][data->player_width] = '0';
    data->map[data->player_height][data->player_width + 1] = 'P';
}