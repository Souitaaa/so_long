/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:18 by csouita           #+#    #+#             */
/*   Updated: 2024/05/03 01:47:15 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char *path)
{
	char	*str;

	str = ft_strrchr(path, '.');
	if (str == NULL)
	{
		write(1, "no .ber file", 13);
		exit(1);
	}
	if (ft_strcmp(".ber", str) != 0)
	{
		write(1, "no .ber file", 13);
		exit(1);
	}
}

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
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
				return ;
			}
		}
		i++;
	}
}

void	clear(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data);
	free(data->mlx_ptr);
	write(1, "error \n .xpm not found", 23);
	exit(1);
}

void	check_file(t_data *data)
{
	destroy_raven(data);
	destroy_flame(data);
	destroy_exit_win(data);
	destroy_player_right(data);
	destroy_player_left(data);
	destroy_ultimate_player_left(data);
	destroy_ultimate_player_right(data);
	destroy_exit(data);
	destroy_wall(data);
	destroy_floor(data);
}

int	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			map_draw(data, i, j);
			draw_player(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
