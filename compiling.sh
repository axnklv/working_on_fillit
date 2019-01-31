clang -Wall -Werror -Wextra -I libft/includes -o solving.o -c solving.c
clang -o test_exec solving.o -I libft/includes -L libft/ -lft