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
int	ft_strncmp(const char *s1, const char *s2, size_t n);




typedef struct data {
int height ;
int width ;
char **map;
char **map2;
void *coin ;
void *player;
void *wall;
void *floor;
void *door;
void *mlx_ptr;
void *mlx_window;
int exit1;
int collectables;
int player;

} t_data;
char	*get_next_line(int fd);
// void freefun(char **ptr
#endif 