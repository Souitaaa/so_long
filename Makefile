NAME = so_long
# CC = cc -Wall -Wextra -Werror -fsanitize=address -g
SRC = map_functions.c get_next_line.c get_next_line_utils.c ft_strlen2.c window.c so_long.c ft_strncmp.c ft_strrchr.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all