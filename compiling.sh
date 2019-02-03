clang -Wall -Werror -Wextra -I libft/includes -o solving.o -c solving.c
clang -Wall -Werror -Wextra -I libft/includes -o ft_sqrt.o -c ft_sqrt.c
clang -o test_exec ft_sqrt.o solving.o -I libft/includes -L libft/ -lft
