/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:18 by csouita           #+#    #+#             */
/*   Updated: 2024/04/26 22:37:45 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_path(char *path)
{
    // int res;
    
    char *str;
    
    //printf("jjjjjjjjjjjjjjjjj");
    str = ft_strrchr(path, '.');
    // printf("%s\n",str);
    if (str == NULL)
    {
        write(1, "no .ber file", 13);
        exit(1);
    }
    // res = ;
    // printf("%d",res);
    if (ft_strcmp(".ber", str) != 0)
    {
        write(1, "no .ber file", 13);
        exit(1);
    }
}
void player_position(t_data *data)
{
    int i = 0;
    int j = 0;

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
                return;
            }
        }
        i++;
    }
    printf("%d\n",data->player_height);
    printf("%d",data->player_width);
}
void check_file(t_data *file)
{
    if (file == NULL)
    {
        write(1, ".xpm doesn't exist", 19);
        exit(1);
    }
}

int draw_map(t_data *data)
{

    int i = 0;
    int j;

    mlx_clear_window(data->mlx_ptr, data->mlx_window);

    while (i < data->height)
    {
        j = 0;
        // printf("\n--------------------------\n");
        while (j < data->width)
        {

            // printf("i -----> %d \n", i);
            // printf("j -----> %d \n", j);

            map_draw(data, i, j);
            j++;
        }
        i++;
    }
    // i = 0;
    // while (i < 5)
    // {
    //     printf("%s\n",data->map[i]);
    //     i++;
    // }

    return 0;
    // draw_map(data);
}