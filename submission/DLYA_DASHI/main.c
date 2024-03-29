/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:45:07 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/22 20:18:58 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		quantity;
	t_list	*tetris;
	int		fd;
	char	**map;

	if (argc != 2)
		usage();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tetris = read_tetris(fd);
		quantity = ft_listlen(tetris);
		if (quantity > 26)
			it_is_error();
		map = fillit(quantity, tetris);
		printing_fin_map(map);
		free_list(tetris);
	}
	return (0);
}

void		printing_fin_map(char **map)
{
	int		j;

	j = 0;
	while (map[j])
	{
		printf("%s\n", map[j]);
		j++;
	}
}
