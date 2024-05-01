/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:55:41 by csouita           #+#    #+#             */
/*   Updated: 2024/05/01 17:18:17 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_data *data)

{
	data->map[data->player_height - 1][data->player_width] = 'P';
	data->map[data->player_height][data->player_width] = '0';
	data->left = 0;
	data->right = 0;
	data->up = 1;
	data->down = 0;
}

void	down(t_data *data)
{
	data->map[data->player_height + 1][data->player_width] = 'P';
	data->map[data->player_height][data->player_width] = '0';
	data->left = 0;
	data->right = 0;
	data->up = 0;
	data->down = 1;
}

void	left(t_data *data)
{
	data->map[data->player_height][data->player_width - 1] = 'P';
	data->map[data->player_height][data->player_width] = '0';
	data->left = 1;
	data->right = 0;
	data->up = 0;
	data->down = 0;
}

void	right(t_data *data)
{
	data->map[data->player_height][data->player_width + 1] = 'P';
	data->map[data->player_height][data->player_width] = '0';
	data->left = 0;
	data->right = 1;
	data->up = 0;
	data->down = 0;
}
