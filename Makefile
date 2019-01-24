# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 22:00:14 by elchrist          #+#    #+#              #
#    Updated: 2019/01/21 22:24:30 by elchrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
# SRC = *.c
# OBJ = $(SRC:.c=.o)
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
FLAGS = -Wall -Wextra -Werror
HEADER = -I ./
LIBFT = ./libft

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc -c $(FLAGS) $(HEADER) $(SRC) $(OBJ) -L $(LIBFT) -lft -o $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean:
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
