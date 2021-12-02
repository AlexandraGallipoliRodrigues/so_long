# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 12:16:29 by agallipo          #+#    #+#              #
#    Updated: 2021/12/02 13:07:59 by agallipo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c map.c
OBJS =  ${SRCS:.c=.o}
LIBFTDIR = libft/
NAME = so_long
CC = gcc
FLAGS =  -g -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: 	${NAME}

${NAME}: ${OBJS}
	make -sC ${LIBFTDIR}
	cp ./libft/libft.a .
	${CC} ${FLAGS} libft.a ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
			make -sC ${LIBFTDIR} clean
			${RM} ${OBJS} libft.a

fclean: clean
		make -sC ${LIBFTDIR} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

