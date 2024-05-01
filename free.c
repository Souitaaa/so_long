/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:35:58 by csouita           #+#    #+#             */
/*   Updated: 2024/05/01 22:54:06 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->height)
	{
		free(data->map2[i]);
		free(data->map[i]);
	}
	free(data->map2);
	free(data->map);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->messi);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
	mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
	mlx_destroy_image(data->mlx_ptr, data->player_left);
	mlx_destroy_image(data->mlx_ptr, data->player_right);
	mlx_destroy_image(data->mlx_ptr, data->exit_win);
	mlx_destroy_image(data->mlx_ptr, data->trophy);
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
