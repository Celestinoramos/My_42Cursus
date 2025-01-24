NAME	= libftprintf.a

SRCS	= ft_checkspecifier.c \
		ft_printf.c \
		ft_printf_character.c \
		ft_printf_hexadecimal.c \
		ft_printf_number.c \
		ft_printf_pointer.c \
		ft_printf_string.c \
		ft_printf_unsigned.c

OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
