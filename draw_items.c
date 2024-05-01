/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:56:55 by csouita           #+#    #+#             */
/*   Updated: 2024/05/01 23:04:22 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill_items(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx_ptr, data->width * 60,
									  data->height * 60, "So_long");
	data->messi = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/raven.xpm",
										&data->image_width, &data->image_height);

	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit.xpm",
									   &data->image_width, &data->image_height);

	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/7ayt.xpm",
									   &data->image_width, &data->image_height);

	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/lard.xpm",
										&data->image_width, &data->image_height);

	data->trophy = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/flame.xpm",
										 &data->image_width, &data->image_height);

	fill_items2(data);
	check_file(data);
}

void fill_items2(t_data *data)
{
	data->exit_win = mlx_xpm_file_to_image(data->mlx_ptr,
										   "./textures/exit_open.xpm", &data->image_width,
										   &data->image_height);

	data->ultimate_player_right = mlx_xpm_file_to_image(data->mlx_ptr,
														"./textures/ultimate_raven_right.xpm", &data->image_width,
														&data->image_height);

	data->ultimate_player_left = mlx_xpm_file_to_image(data->mlx_ptr,
													   "./textures/ultimate_raven_left.xpm", &data->image_width,
													   &data->image_height);

	data->player_left = mlx_xpm_file_to_image(data->mlx_ptr,
											  "./textures/raven_left.xpm", &data->image_width,
											  &data->image_height);

	data->player_right = mlx_xpm_file_to_image(data->mlx_ptr,
											   "./textures/raven_right.xpm", &data->image_width,
											   &data->image_height);
}

void map_draw(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->wall, j * 60, i * 60);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->floor, j * 60, i * 60);
	else if (data->map[i][j] == 'E')
	{
		if (all_collected(data))
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->exit_win, j * 60, i * 60);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->exit,
									j * 60, i * 60);
	}
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->trophy, j * 60, i * 60);
}

void draw_player(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		if (all_collected(data) && data->left)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->ultimate_player_left, j * 60, i * 60);
		else if (all_collected(data) && data->up)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->ultimate_player_left, j * 60, i * 60);
		else if (all_collected(data) && data->down)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->ultimate_player_left, j * 60, i * 60);
		else if (all_collected(data) && data->right)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->ultimate_player_right, j * 60, i * 60);
		else if (data->left)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->player_left, j * 60, i * 60);
		else if (data->right)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->player_right, j * 60, i * 60);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
									data->messi, j * 60, i * 60);
	}
}
// void files(t_data *data)
// {
// 	int check = 0;
// 	if (data->messi != NULL)
// 	{
// 		free(data->messi);
// 		check = 1;
// 	}
// 	if (data->wall != NULL)
// 	{
// 		free(data->wall);
// 		check = 1;
// 	}
// 	if (data->exit_win != NULL)
// 	{
// 		free(data->exit_win);
// 		check = 1;
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
// 		check = 1;
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
// 	if (check == 0)
// 	{
// 		write(1, "map.xber", 9);
// 		exit(1);
// 	}
// }
