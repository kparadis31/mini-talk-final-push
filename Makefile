# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kparadis <je73@hotmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 20:13:22 by kparadis          #+#    #+#              #
#    Updated: 2023/07/30 18:40:22 by kparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = minitalk

SRCS	 = ft_printf.c\
			ft_print_hexa_maj.c\
			ft_print_hexa_min.c\
			ft_put_everything.c\
			ft_putchar.c\
			ft_putnbr_dec.c\
			ft_putnbr.c\
			ft_putstr.c\
			ft_unsigned_nbr.c\
			utils.c

CLIENT   = client

SERVER   = server

CC       = gcc

CFLAGS   = -Wall -Wextra -Werror

all      : ${NAME}

${NAME}  : ${CLIENT} ${SERVER}

${CLIENT}: client.c ${SRCS}
				$(CC) $(CFLAGS) client.c ${SRCS} -o client

${SERVER}: server.c ${SRCS}
				$(CC) $(CFLAGS) server.c ${SRCS} -o server

clean    :
				@rm -f ${CLIENT} ${SERVER}

fclean   : clean

re       : fclean all

.PHONY   : all bonus clean fclean re
