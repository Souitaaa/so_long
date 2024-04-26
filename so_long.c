/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:38 by csouita           #+#    #+#             */
/*   Updated: 2024/04/26 15:13:12 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keycode_print(int keycode, t_data *data)
{
    (void)data;
    printf("%d\n", keycode);
    return 0;
}
int move_player(int keycode, t_data *data)
{
    // printf("proob %d",keycode);
    if (keycode == UP_KEY || keycode == W)
        print_up(data);
    if (keycode == LEFT_KEY || keycode == A)
        print_left(data);
    if (keycode == DOWN_KEY || keycode == S)
        print_down(data);
    if (keycode == RIGHT_KEY || keycode == D)
        print_right(data);
    player_position(data);
    draw_map(data);

    return 0;
}

int main(int ac, char *av[])
{
    (void)ac;
    t_data data;
    data.moves = 0;
    data.player_height = 0 ;
    data.player_width = 0 ;
    // printf("machaki safi");
    // data.mlx_ptr = mlx_init();
    ft_memset(&data, 0, sizeof(int));


    // map_arr2(av[1],&data);

    data.height = 0;
    check_path(av[1]);
    map_check(av[1], &data);
    map_width(av[1], &data);
    map_arr(av[1], &data);
    check_map_border(&data);
    store_content(&data);
    check_exist_items(&data);
    check_file(&data);
    fill_items(&data);
    draw_map(&data);
    player_position(&data);
    // flood(&data);
    mlx_key_hook(data.mlx_window, move_player, &data);
    mlx_loop_hook(data.mlx_ptr, draw_map, &data);
    draw_map(&data);
    mlx_loop(data.mlx_ptr);
    // printf("%d",data.height);
}
