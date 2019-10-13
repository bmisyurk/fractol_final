NAME		= fractol
SRCS		=	main.c \
				mandelbrot.c \
				tricorn.c \
				celtic.c \
				julia.c \
				ship.c \
				mandelbar.c \
				heart.c \
				out_error.c \
				key_hooks.c \
				mlx.c \
				fract_init.c \
				color.c \
				text.c \

SRCO		= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror
HEADER      = -I /usr/local/include/ -I includes/
MLX			= -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit -lm -lpthread
LIBS		= libft/libft.a 
LIB_DIR = libft/
DIR = obj
SRC = $(SRCS)
OBJ = $(addprefix $(DIR)/,$(SRCO))

all: $(NAME)


$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@cc $(OBJ) -o $(NAME) $(HEADER) $(MLX) -L $(LIB_DIR) -lft
	@echo "     *****     fractol complied     *****     "


obj/%.o: %.c
	@mkdir -p $(DIR)
	@gcc -c $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
