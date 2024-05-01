/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:34:47 by csouita           #+#    #+#             */
/*   Updated: 2024/04/30 18:22:27 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	store_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->collectables = 0;
	data->player = 0;
	data->exit1 = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'E')
				data->exit1++;
			else if (data->map[i][j] == 'P')
				data->player++;
			else if (data->map[i][j] == 'C')
				data->collectables++;
			j++;
		}
		i++;
	}
	if_map_valid(data);
}

void	if_map_valid(t_data *data)
{
	if (data->player != 1 || data->collectables < 1 || data->exit1 != 1)
	{
		write(1, "map is not valid", 17);
		free_map(data);
		exit(1);
	}
}

void	check_exist_items(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j > data->width)
		{
			if (data->map[i][j] != 'P' || data->map[i][j] != 'C'
				|| data->map[i][j] != 'E')
			{
				write(1, "error in items , double check them please !", 44);
				free_map(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
	store_content(data);
}
