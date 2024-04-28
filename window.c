#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500

// void load_images(t_data *data) {
//     data->player = mlx_xpm_file_to_image(data->mlx_ptr, "textures/bottom.xpm", &data->width, &data->height);
//     data->coin = mlx_xpm_file_to_image(data->mlx_ptr, "textures/coin42.xpm", &data->width, &data->height);
//     data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "textures/wall.xpm", &data->width, &data->height);
//     data->door = mlx_xpm_file_to_image(data->mlx_ptr, "textures/DOOR.xpm", &data->width, &data->height);
// }

// void    print_imgs(t_data *data, int height)
// {
    
//     load_images(data);
    
//     int i = 0;
//     int j = 0;
//     while (i < height && data->map != NULL && data->map[i] != NULL)
//     {
//         j = 0;
//         while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
//         {
//             if (data->map[i][j] == '1') 
//                 mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->wall, j * 64, i * 64);
//             if (data->map[i][j] == 'C') 
//                 mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->coin, j * 64, i * 64);
//             if (data->map[i][j] == 'P' || data->map[i][j] == '0' ) 
//                 mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->player, j * 64, i * 64);
//             if (data->map[i][j] == 'E') 
//                 mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->door, j * 64, i * 64);
//             j++;
//         }
//         i++;
//     }
// }

// int main()
// {
//     void *mlx_ptr ;
//     void *mlx_window;

//     mlx_ptr = mlx_init();
//     mlx_window = mlx_new_window(mlx_ptr,500,500,"hello world!");

//     mlx_loop(mlx_ptr);
// }