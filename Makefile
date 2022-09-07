NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := logic_srcs/*.c
GETNEXTLINE := get_next_line/*.c
LIBRARY := -L minilibx -lmlx -framework OpenGL -framework AppKit
LIBFT := Libft/*.c
PRINTF := ft_printf/*.c
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBFT) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
			make clean -C $(MINILIBX)
			rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re