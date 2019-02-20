# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 22:00:14 by elchrist          #+#    #+#              #
#    Updated: 2019/02/20 22:12:22 by creek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
OBJ = $(SRC:.c=.o)
# SRC = $(wildcard *.c)
# OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
FLAGS = -Wall -Wextra -Werror
HEADER = -I fillit.h
LIBFT = libft/
LIBINCLUDES = -I /libft/includes

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc -o fillit main.c solving.c validation.c reading.c lib_functions.c list_functions.c -I fillit.h -I libft/includes -L libft/ -lft
	#gcc -c $(FLAGS) $(HEADER) $(SRC) $(OBJ) $(LIBINCLUDES) -L $(LIBFT) -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(HEADER) -c $^ -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean:
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
