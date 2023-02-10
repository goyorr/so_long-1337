# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:42:07 by zel-kach          #+#    #+#              #
#    Updated: 2022/12/20 10:42:11 by zel-kach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

SRC = so_long.c \
	  ft_putstuff.c ft_checkstuff.c \
	  get_next_line_utils.c get_next_line.c \
	  ft_move.c playable.c

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

$(NAME): $(OBJ) so_long.h
	     $(CC) $(OBJ) -lmlx -framework OpenGl -framework AppKit -o $@

%.o: %.c SoLong.h
	 ${CC} ${CFLAGS} -c $<

clean:
	  ${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re