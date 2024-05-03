/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:38 by csouita           #+#    #+#             */
/*   Updated: 2024/05/03 18:02:41 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_rectangle(t_data *data)
{
	int	i;

	i = 0;
	if (data->height == data->width)
	{
		write(1, "Error\nmap is not rectangular", 29);
		exit(1);
	}
}

int	all_collected(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	move_player(int keycode, t_data *data)
{
	if (keycode == Q || keycode == ESC)
		close_window(data);
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
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 2)
	{
		ft_memset(&data, 0, sizeof(t_data));
		check_path(av[1]);
		map_check(av[1], &data);
		map_width(av[1], &data);
		map_rectangle(&data);
		map_arr(av[1], &data);
		check_map_border(&data);
		check_exist_items(&data);
		(fill_items(&data), player_position(&data));
		flood_fill(&data, data.player_height, data.player_width);
		(flood_fill_checker(&data), draw_map(&data));
		mlx_key_hook(data.mlx_window, move_player, &data);
		mlx_hook(data.mlx_window, 17, 0, close_window, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		(write(1, "Error\ntoo many arguments", 25), exit(1));
}
