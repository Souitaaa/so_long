#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>



# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//------------------------------Get_next_line------------------------------//
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
//-------------------------------------------------------------------------//
char	*ft_strdup(char *s);
size_t ft_strlen2(char *str);
char	*ft_strrchr(const char *s, int c);
int	ft_strcmp(char *s1, char *s2);
size_t ft_count_digits(int number);
char *ft_itoa(int number);
int ft_putstr(char *str);
int	ft_putchar(int c);


typedef struct data {
int height ;
int width ;
char **map;
char **map2;
void *coin ;
// void *player;
void *door;
void *mlx_ptr;
void *mlx_window;
int exit1;
int collectables;
int player;
int player_height;
int player_width;
void *messi;
void *wall;
void *floor;
void *exit;
void *enemy;
void *trophy;
int  image_height;
int  image_width;
int moves;


} t_data;

void store_content(t_data *data);
void check_exist_items(t_data *data);
void map_check(char *path, t_data *data);
void map_width(char *path, t_data *data);
void map_arr(char *path, t_data *data);
void map_arr2(char *path, t_data *data);
void check_map_border(t_data *data);
void freefun(char **ptr);
void check_path(char *path);
void player_position(t_data *data);
void fill_items(t_data *data);
char	*get_next_line(int fd);
void map_draw(t_data *data, int i , int j);
void close_window(t_data *data);
void up(t_data *data);
void down(t_data *data);
void left(t_data *data);
void right(t_data *data);
void check_file(t_data *xcheck);
void print_up(t_data *data);
void print_down(t_data *data);
void print_left(t_data *data);
void print_right(t_data *data);



// void freefun(char **ptr
#endif 