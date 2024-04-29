#include "so_long.h"

void fill_items(t_data *data)
{
    data->mlx_ptr = mlx_init();
    data->mlx_window = mlx_new_window(data->mlx_ptr, data->width * 60, data->height * 60, "messi's journey");
    data->messi = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/thief.xpm", &data->image_width, &data->image_height);
    check_file(data->messi);
    data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit.xpm", &data->image_width, &data->image_height);
    check_file(data->exit);
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/7ayt.xpm", &data->image_width, &data->image_height);
    check_file(data->wall);
    data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/lard.xpm", &data->image_width, &data->image_height);
    check_file(data->floor);
    data->trophy = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/ballon d'or.xpm", &data->image_width, &data->image_height);
    check_file(data->trophy);
    data->exit_win = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit_open.xpm", &data->image_width, &data->image_height);
    check_file(data->exit_win);
    data->ultimate_player = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/ultimate_raven.xpm", &data->image_width, &data->image_height);
    check_file(data->ultimate_player);
    data->player_left = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_left.xpm", &data->image_width, &data->image_height);
    check_file(data->player_left);
    data->player_right = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player_right.xpm", &data->image_width, &data->image_height);
    check_file(data->player_right);
}

void map_draw(t_data *data, int i, int j)
{
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->floor, j * 60, i * 60);
    if (data->map[i][j] == '1')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->wall, j * 60, i * 60);
    else if (data->map[i][j] == '0')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->floor, j * 60, i * 60);
    else if (data->map[i][j] == 'E')
    {
        if (all_collected(data))
            mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->exit_win, j * 60, i * 60);
        else
            mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->exit, j * 60, i * 60);
    }
    // if (all_collected(data)){
    //     exit(0);
    // mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->exit, j * 60, i * 60);
    // }
    else if (data->map[i][j] == 'C')
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->trophy, j * 60, i * 60);
    else if (data->map[i][j] == 'P')
    {
        if (all_collected(data))
            mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->ultimate_player, j * 60, i * 60);
        else if (data->left)
            mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->player_left, j * 60, i * 60);
        else if (data->right)
            mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->player_right, j * 60, i * 60);
        else
            mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->messi, j * 60, i * 60);
    }
}
int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->mlx_window);
    mlx_clear_window(data->mlx_ptr, data->mlx_window);
    mlx_destroy_image(data->mlx_ptr, data->floor);
    mlx_destroy_image(data->mlx_ptr, data->wall);
    mlx_destroy_image(data->mlx_ptr, data->messi);
    mlx_destroy_image(data->mlx_ptr, data->exit);
    mlx_destroy_image(data->mlx_ptr, data->exit_win);
    mlx_destroy_image(data->mlx_ptr, data->trophy);
    mlx_destroy_display(data->mlx_ptr);
    exit(0);
    return 0;
}