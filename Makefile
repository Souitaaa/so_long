NAME = so_long
CC = cc -Wall -Wextra -Werror #-fsanitize=address -g
SRC = utils.c map_functions.c get_next_line.c get_next_line_utils.c ft_strlen2.c \
  ft_strncmp.c ft_strrchr.c check_content.c draw_items.c moves.c print_moves.c \
 ft_putstr.c ft_putchar.c ft_itoa.c ft_memset.c so_long.c flood_fill.c 
OBJ = $(SRC:.c=.o)
all: $(NAME)

%.o: %.c
	@$(CC)  -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "naaaadi ✅"

$(NAME): $(OBJ)
	@$(CC)  $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all