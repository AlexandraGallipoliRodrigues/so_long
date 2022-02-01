# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 12:16:29 by agallipo          #+#    #+#              #
#    Updated: 2022/02/01 11:58:54 by agallipo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/so_long.c  srcs/map.c srcs/enemy.c

OBJS =  ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

LIBFTDIR = libft/
NAME = so_long
CC = gcc
FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: 	${NAME}

${NAME}: ${OBJS}
	make -sC ${LIBFTDIR}
	cp ./libft/libft.a .
	${CC} ${FLAGS} libft.a ${OBJS} -I ${INCLUDES} -o ${NAME}

%.o: %.c
	${CC} ${FLAGS} -I ${INCLUDES} -c $< -o $@


clean:
			make -sC ${LIBFTDIR} clean
			${RM} ${OBJS} libft.a

fclean: clean
		make -sC ${LIBFTDIR} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

