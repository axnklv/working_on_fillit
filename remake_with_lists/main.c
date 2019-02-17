/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:45:07 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/17 17:20:45 by creek            ###   ########.fr       */
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
	char **map;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tetris = read_tetris(fd);
		quantity = ft_listlen(tetris);
		map = fillit(quantity, tetris); // ТУТ СЕГФОЛТ
		//printing_fin_map(map);
		//free_list(tetris);

	}
	return (0);
}

void printing_fin_map(char **map)
{
	int i, j;
	i = 0;
	j = 0;
	while (map[j])
	{
		printf("%s\n", map[j]);
		j++;
	}
}
