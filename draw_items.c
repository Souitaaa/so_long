#include "so_long.h"

void fill_items(t_data *data)
{
    data->mlx_ptr = mlx_init();
    data->mlx_window = mlx_new_window(data->mlx_ptr, 60, 60, "messi's journey");
    data->messi = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/thief.xpm", &data->image_width, &data->image_height);
    check_file(data->messi);
    data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit.xpm", &data->image_width, &data->image_height);
    check_file(data->exit);
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/7ayt.xpm", &data->image_width, &data->image_height);
    check_file(data->wall);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/lard.xpm", &data->image_width, &data->image_height);
    check_file(data->floor);
    data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/enermy hh.xpm", &data->image_width, &data->image_height);
    check_file(data->enemy);
    data->trophy = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/ballon d'or.xpm", &data->image_width, &data->image_height);
    check_file(data->trophy);
}
void map_draw(t_data *data, int i, int j)
{
    if (data->map[i][j] == '1')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->wall, j * 60, i * 60);
    else if (data->map[i][j] == '0')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->floor, j * 60, i * 60);
    else if (data->map[i][j] == 'E')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->exit, j * 60, i * 60);
    else if (data->map[i][j] == 'C')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->trophy, j * 60, i * 60);
    else if (data->map[i][j] == 'P')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->messi, j * 60, i * 60);
}
void close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->mlx_window);
}