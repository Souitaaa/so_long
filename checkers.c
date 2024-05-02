/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:56:27 by csouita           #+#    #+#             */
/*   Updated: 2024/05/02 02:28:33 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_floor(t_data *data)
{
	if (!data->floor)
	{
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}

void	destroy_wall(t_data *data)
{
	if (!data->wall)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}

void	destroy_exit(t_data *data)
{
	if (!data->exit)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}

void	destroy_ultimate_player_right(t_data *data)
{
	if (!data->ultimate_player_right)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}

void	destroy_ultimate_player_left(t_data *data)
{
	if (!data->ultimate_player_left)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}
