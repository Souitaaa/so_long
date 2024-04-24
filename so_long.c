#include "so_long.h"
int r;
void check_path(char *path)
{
    // int res;
    char *str;

    str = ft_strrchr(path, '.');
    // printf("%s\n",str);
    if (str == NULL)
    {
        write(1, "no .ber file", 13);
        exit(1);
    }
    // res = ;
    // printf("%d",res);
    if (ft_strcmp(".ber", str) != 0)
    {
        write(1, "no .ber file", 13);
        exit(1);
    }
}
void player_position(t_data *data)
{
    int i = 0;
    int j = 0;

    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (data->map[i][j] != 'P')
                j++;
            else if (data->map[i][j] == 'P')
            {
                data->player_height = i;
                data->player_width = j;
                return;
            }
        }
        i++;
    }
    // printf("%d\n",data->player_height);
    // printf("%d",data->player_width);
}
void check_file(t_data *xcheck)
{
    if (xcheck == NULL)
    {
        write(1, ".xpm doesn't exist", 19);
        exit(1);
    }
}

// void	path_check(char *path)
// {
// 	char	*extention;

// 	extention = ft_strrchr(path, '.');
// 	if (extention == NULL)
// 	{
// 		write(1,"do not have extention",22);
// 		exit(1);
// 	}
// 	if (strcmp(extention, ".ber") != 0)
// 	{
// 		write(1,"extention False",16);
// 		exit(1);
// 	}
// }
void draw_map(t_data *data)
{

    int i = 0;
    int j;

    mlx_clear_window(data->mlx_ptr, data->mlx_window);

    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            // printf("i -----> %d \n", i);
            // printf("j -----> %d \n", j);
            mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->floor, j * 60, i * 60);

            map_draw(data, i, j);
            j++;
        }
        i++;
    }
    //draw_map(data);
}

int main(int ac, char *av[])
{
    (void)ac;
    t_data data;
    // data.mlx_ptr = mlx_init();
    ft_memset(&data, 0, sizeof(int));
    data.height = 0;
    map_check(av[1], &data);
    map_width(av[1], &data);
    check_path(av[1]);
    map_arr(av[1], &data);
    check_map_border(&data);
    store_content(&data);
    check_exist_items(&data);
    player_position(&data);
    fill_items(&data);
    draw_map(&data);
    // mlx_key_hook(data.mlx_window,&keycode_print, &data);
    //mlx_loop_hook(data.mlx_ptr, draw_map, &data);
    mlx_loop(data.mlx_ptr);
    // printf("%d",data.height);
}
