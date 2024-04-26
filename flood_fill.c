/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:29:03 by csouita           #+#    #+#             */
/*   Updated: 2024/04/26 14:58:44 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(int x, int y, t_data *data)
{
    if (data->visited == 0 && data->map[data->player_height][data->player_width] == '0' || data->map[data->player_height][data->player_width] == 'P' || data->map[data->player_height][data->player_width] == 'C')
    {
        data->visited = 1;
        if (data->map[data->player_height][data->player_width] == 'C')
            data->coins_found++;
    }
    flood_fill(data->player_height + 1, data->player_width, data);
    flood_fill(data->player_height - 1,data->player_width,data);
    flood_fill(data->player_height,data->player_width + 1, data);
    flood_fill(data->player_height,data->player_width - 1, data);
}
