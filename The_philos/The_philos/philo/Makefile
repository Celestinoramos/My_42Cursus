NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = 	src/philo.c src/arguments_checker.c src/init_global.c \
		 src/philo_rotine.c src/rotine_utils1.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
