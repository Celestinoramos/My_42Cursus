# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svula <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 15:11:00 by svula             #+#    #+#              #
#    Updated: 2024/07/17 15:11:03 by svula            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRCS1 = server.c
SRCS2 = client.c

OBJECTO1 = ${SRCS1:.c=.o}
OBJECTO2 = ${SRCS2:.c=.o}

HEADERS = minitalk.h
CFLAGS = -Werror -Wall -Wextra -g

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

.c.o:
			@cc ${CFLAGS} -c $^ -o $@

all:		${SERVER} ${CLIENT}

${SERVER}: ${OBJECTO1} ${FT_PRINTF_LIB}
					@cc ${OBJECTO1} ${FT_PRINTF_LIB} $(CFLAGS) -o ${SERVER}
					
${CLIENT}: ${OBJECTO2} ${FT_PRINTF_LIB}
					@cc ${OBJECTO2} ${FT_PRINTF_LIB} $(CFLAGS) -o ${CLIENT}

${FT_PRINTF_LIB}:
			@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
			@rm -f ${OBJECTO1}
			@rm -f ${OBJECTO2}
			@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean:		clean
			@rm -f ${SERVER}
			@rm -f ${CLIENT}
			@echo "Foi apagado tudo com sucesso!"
			@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

