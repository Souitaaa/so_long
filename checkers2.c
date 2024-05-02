/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:01:55 by csouita           #+#    #+#             */
/*   Updated: 2024/05/02 02:30:14 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_player_left(t_data *data)
{
	if (!data->player_left)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}

void	destroy_player_right(t_data *data)
{
	if (!data->player_right)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}

void	destroy_exit_win(t_data *data)
{
	if (!data->exit_win)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->flame);
		clear(data);
	}
}

void	destroy_flame(t_data *data)
{
	if (!data->flame)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->raven);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		clear(data);
	}
}

void	destroy_raven(t_data *data)
{
	if (!data->raven)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
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
