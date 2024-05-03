/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:09:36 by csouita           #+#    #+#             */
/*   Updated: 2024/05/03 03:36:49 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define A 97
# define W 119
# define S 115
# define D 100
# define Q 113
# define ESC 65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
//------------------------------Get_next_line------------------------------//
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strjoin(char *s1, char *s2);
//-------------------------------------------------------------------------//
char		*ft_strdup(char *s);
size_t		ft_strlen2(char *str);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_count_digits(int number);
char		*ft_itoa(int number);
int			ft_putstr(char *str);
int			ft_putchar(int c);
void		*ft_memset(void *b, int c, size_t len);

typedef struct data
{
	int		height;
	int		width;
	char	**map;
	char	**map2;
	void	*door;
	void	*mlx_ptr;
	void	*mlx_window;
	int		exit1;
	int		collectables;
	int		player;
	int		player_height;
	int		player_width;
	void	*raven;
	void	*exit_win;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*flame;
	void	*ultimate_player_right;
	void	*ultimate_player_left;
	void	*player_right;
	void	*player_left;
	int		left;
	int		right;
	int		up;
	int		down;
	int		image_height;
	int		image_width;
	int		moves;
	int		keycode;
}			t_data;

void		store_content(t_data *data);
void		check_exist_items(t_data *data);
void		map_check(char *path, t_data *data);
void		map_width(char *path, t_data *data);
void		map_arr(char *path, t_data *data);
void		check_map_border(t_data *data);
void		check_path(char *path);
void		player_position(t_data *data);
void		fill_items(t_data *data);
char		*get_next_line(int fd);
void		map_draw(t_data *data, int i, int j);
int			close_window(t_data *data);
void		up(t_data *data);
void		down(t_data *data);
void		left(t_data *data);
void		right(t_data *data);
void		check_file(t_data *file);
void		print_up(t_data *data);
void		print_down(t_data *data);
void		print_left(t_data *data);
void		print_right(t_data *data);
int			draw_map(t_data *data);
int			move_player(int keycode, t_data *data);
void		flood_fill(t_data *data, int i, int j);
void		flood_fill_checker(t_data *data);
void		map_arr2(char *path, t_data *data);
int			all_collected(t_data *data);
void		map_rectangle(t_data *data);
void		if_map_valid(t_data *data);
void		fill_items2(t_data *data);
void		draw_player(t_data *data, int i, int j);
void		you_won(t_data *data);
void		free_map(t_data *data);
void		check_fd(int fd);
void		destroy_raven(t_data *data);
void		destroy_flame(t_data *data);
void		destroy_exit_win(t_data *data);
void		destroy_player_right(t_data *data);
void		destroy_player_left(t_data *data);
void		destroy_ultimate_player_left(t_data *data);
void		destroy_ultimate_player_right(t_data *data);
void		destroy_exit(t_data *data);
void		destroy_wall(t_data *data);
void		destroy_floor(t_data *data);
void		clear(t_data *data);
#endif