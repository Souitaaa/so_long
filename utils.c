/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:18 by csouita           #+#    #+#             */
/*   Updated: 2024/05/01 22:43:09 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_path(char *path)
{
	char *str;

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

void player_position(t_data *data)
{
	int i;
	int j;

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
				return;
			}
		}
		i++;
	}
}

// void	check_file(t_data *data)
// {
// 	int check = 0 ;
// 	if (data->messi != NULL)
// 	{
// 		free(data->messi);
// 		check = 1;
// 	}
// 	if (data->wall != NULL)
// 	{
// 		free(data->wall);
// 		check = 1 ;
// 	}
// 	if (data->exit_win != NULL)
// 	{
// 		free(data->exit_win);
// 		check = 1 ;
// 	}
// 	if (data->exit != NULL)
// 	{
// 		free(data->exit);
// 		check = 1;
// 	}
// 	if (data->trophy != NULL)
// 	{
// 		free(data->trophy);
// 		check = 1;
// 	}
// 	if (data->floor != NULL)
// 	{
// 		free(data->floor);
// 		check = 1 ;
// 	}
// 	if (data->player_left != NULL)
// 	{
// 		free(data->player_left);
// 		check = 1;
// 	}
// 	if (data->player_right != NULL)
// 	{
// 		free(data->player_right);
// 		check = 1;
// 	}
// 	if (data->ultimate_player_left != NULL)
// 	{
// 		free(data->ultimate_player_left);
// 		check = 1;
// 	}
// 	if (data->ultimate_player_right != NULL)
// 	{
// 		free(data->ultimate_player_right);
// 		check = 1;
// 	}
// 	printf("%d\n",check);
// 	if (check != 0)
// 		{
// 			write(1,"map.xber",9);
// 			exit(1);
// 		}
// }

void clear(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data);
	free(data->mlx_ptr);
	write(1,"tssawr ghalt",13);
	exit(1);
}

void check_file(t_data *data)
{
	if (!data->messi)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}
	if (!data->floor)
	{
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->wall)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->exit)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->ultimate_player_right)
	{
			mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->ultimate_player_left)
	{
			mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->player_left)
	{
			mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->player_right)
	{
			mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->exit_win);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->exit_win)
	{
		mlx_destroy_image(data->mlx_ptr, data->floor);
		mlx_destroy_image(data->mlx_ptr, data->wall);
		mlx_destroy_image(data->mlx_ptr, data->messi);
		mlx_destroy_image(data->mlx_ptr, data->exit);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_right);
		mlx_destroy_image(data->mlx_ptr, data->ultimate_player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_left);
		mlx_destroy_image(data->mlx_ptr, data->player_right);
		mlx_destroy_image(data->mlx_ptr, data->trophy);
		clear(data);
	}

	if (!data->trophy)
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
		clear(data);
	}

}

int draw_map(t_data *data)
{
	int i;
	int j;

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
