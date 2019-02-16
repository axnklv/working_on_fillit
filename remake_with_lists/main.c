/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:45:07 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/16 20:26:01 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "solving.h"

void it_is_error(void)
{
    write(1, "error\n", 6);
    exit(1);
}

int			main(int argc, char **argv)
{
	int quantity;
	t_list	*tetris;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tetris = read_tetris(fd);
		quantity = ft_listlen(tetris);
		fillit(quantity, tetris);
		print_list(tetris); //функция просто для теста, выводит адреса)))0)
		//fillit(tetris); //какая-нибудь итоговая функция, в которую всё собрано
		//free_list(tetris);
	}
	return (0);
}
