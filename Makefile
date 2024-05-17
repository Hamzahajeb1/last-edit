NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): main.c init.c hooks.c render.c utils.c functions.c minilibx-linux/libmlx_Linux.a
	$(CC) $(CFLAGS) -Lminilibx-linux -lmlx -lXext -lX11 $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re