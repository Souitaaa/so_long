NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
CPPFLAGS = -I$(MLX_DIR)
SRC = utils.c map_functions.c get_next_line.c get_next_line_utils.c ft_strlen2.c \
  ft_strncmp.c ft_strrchr.c check_content.c draw_items.c moves.c print_moves.c \
 ft_putstr.c ft_putchar.c ft_itoa.c ft_memset.c so_long.c flood_fill.c free.c \
 checkers.c checkers2.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

%.o: %.c so_long.h get_next_line.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -lXext -lX11 -lm -lz -o $(NAME)


clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY : $(OBJ)
.PHONY: all clean fclean re
