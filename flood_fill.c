/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:29:03 by csouita           #+#    #+#             */
/*   Updated: 2024/05/11 20:05:55 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *data, int i, int j)
{
	if (data->map2[i][j] != '0' && data->map2[i][j] != 'C'
		&& data->map2[i][j] != 'E' && data->map2[i][j] != 'P')
		return ;
	else if (data->map2[i][j] == 'E')
	{
		data->map2[i][j] = '+';
		return ;
	}
	data->map2[i][j] = 'X';
	flood_fill(data, i + 1, j);
	flood_fill(data, i - 1, j);
	flood_fill(data, i, j + 1);
	flood_fill(data, i, j - 1);
}

void	flood_fill_checker(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map2[i][j] == 'E' || data->map2[i][j] == 'C')
			{
				write(1, "Error\nmap is unplayable", 24);
				close_window(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
