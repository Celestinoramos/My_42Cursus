NAME = fractol
CC = cc
CFLAGS	= -Werror -Wextra -Wall
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

INC = -I ./includes/\
	-I ./minilibx-linux/
SRC_PATH = src/
SRC =	fractol.c \
	initialization.c \
	fractol_utils1.c \
	fractol_utils2.c \
	fractol_utils3.c \
	fractol_utils4.c \
	events.c \
	render.c \
	color.c \
	parse_args.c \
	intro.c \
	mandelbrot.c \
	julia.c \
	color_utils1.c \
	color_utils2.c \
	color_utils3.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)

$(MLX):
	@make -C $(MLX_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lXext -lX11 -lm -lbsd

re: fclean all

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(MLX_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(MLX_PATH) clean

.PHONY: all re clean fclean

