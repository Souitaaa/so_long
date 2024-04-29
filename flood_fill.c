/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:29:03 by csouita           #+#    #+#             */
/*   Updated: 2024/04/28 21:39:33 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void flood_fill(int x, int y, t_data *data)
// {
//     if (data->visited == 0 && (data->map[data->player_height][data->player_width] == '0' || data->map[data->player_height][data->player_width] == 'P' || data->map[data->player_height][data->player_width] == 'C'))
//     {
//         data->visited = 1;
//         if (data->map[data->player_height][data->player_width] == 'C')
//             data->coins_found++;
//     }
//     flood_fill(data->player_height + 1, data->player_width, data);
//     flood_fill(data->player_height - 1,data->player_width,data);
//     flood_fill(data->player_height,data->player_width + 1, data);
//     flood_fill(data->player_height,data->player_width - 1, data);
// }

void flood_fill(t_data *data, int i, int j)
{
	if (data->map2[i][j] != '0' && data->map2[i][j] != 'C' && data->map2[i][j] != 'E' && data->map2[i][j] != 'P')
		return;
	else if (data->map2[i][j] == 'E')
	{
		data->map2[i][j] = '+';
		return;
	}
	data->map2[i][j] = 'X';
	flood_fill(data, i + 1, j);
	flood_fill(data, i - 1, j);
	flood_fill(data, i, j + 1);
	flood_fill(data, i, j - 1);
}

void flood_fill_checker(t_data *data)
{
	int i = 0;
	int j = 0;

	while (i < data->height)
	{
		// printf("%s\n", data->map2[i]);
		// printf("%d\n", i);

		j = 0;
		while (j < data->width)
		{
			if (data->map2[i][j] == 'E' || data->map2[i][j] == 'C')
			{
				write(1, "map is unplayable", 18);
				exit(1);
			}
			j++;
		}
		i++;
	}
}