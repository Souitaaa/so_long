#include "so_long.h"

void up(t_data *data)

{
    // if (data->map[data->player_height - 1][data->player_width] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    // else
    data->map[data->player_height - 1][data->player_width] = 'P';
    data->map[data->player_height][data->player_width] = '0';
   
}

// void up(t_data *data)

// {
//     if (data->player_height == 3 && data->player_width == 11 && all_collected(data))
//     {
//           data->map[1][11] = '1';
//           data->map[15][30] = 'E';

//         //data->map[1][12] = '1';
//     }


//     data->map[data->player_height - 1][data->player_width] = 'P';
//     data->map[data->player_height][data->player_width] = '0';
   
// }
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

// void left(t_data *data)
// {
//     if(data->map[data->player_height][data->player_width - 2] =='E')
//     {
//         data->map[data->player_height][data->player_width - 2] = '0';
//         data->map[1][11] = 'E';
//         //data->flag = 1;
//         //data->map[1][12] = '1';
//     }
// }
//     // printf("%d",data->player_height)
//     if (data->player_height == 1 && data->player_width == 3 && all_collected(data))
//     {
//         data->map[data->player_height][data->player_width - 2] = '0';
//         data->map[1][11] = 'E';
//         //data->map[1][12] = '1';
//     }

//     if (data->player_height == 1 && data->player_width == 15 && all_collected(data))
//     {
//             data->map[1][12] = '1';
//             data->map[2][11] = '0';
//             data->map[3][11] = '0';
//     }
//     // else if(data->map[data->player_height][data->player_width - 2] == 'E' /*&& data->flag == 1*/)
//     // {
//     //     printf("hhhhhhh");
//     //     //data->map[data->player_height][data->player_width - 2] = 'E';
//     //     data->map[1][12] = '1';
//     //     //data->flag = 1;
//     // }
//     // if (data->map[data->player_height][data->player_width - 1] == '1')
//     //     data->map[data->player_height][data->player_width] = 'P';
//     data->map[data->player_height][data->player_width - 1] = 'P';
//     data->map[data->player_height][data->player_width] = '0';
//     data->left = 1;
//     data->right = 0;

// }
void right(t_data *data)
{
    // if (data->map[data->player_height - 1][data->player_width + 1] == '1')
    //     data->map[data->player_height][data->player_width] = 'P';
    data->map[data->player_height][data->player_width + 1] = 'P';
    data->map[data->player_height][data->player_width] = '0';
    data->left = 0;
    data->right = 1;
}
// void right(t_data *data)
// {
//     if (data->player_height == 15 && data->player_width == 27 && all_collected(data))
//     {
//           data->map[15][26] = '1';
//           data->map[15][29] = '1';

//         //data->map[1][12] = '1';
//     }
//     data->map[data->player_height][data->player_width + 1] = 'P';
//     data->map[data->player_height][data->player_width] = '0';
//     data->left = 0;
//     data->right = 1;
// }