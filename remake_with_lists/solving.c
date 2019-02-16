/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:41:43 by creek             #+#    #+#             */
/*   Updated: 2019/02/16 20:34:41 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solving.h"

/* quantity передается от Сашеньки = ft_listlen */

int ft_sqrt_round_up(int nb)
{
    int i;

    i = 0;
    while ((i * i) <= nb)
    {
		if ((i * i) == nb)
            return (i);
		i++;
    }
    return (i++);
}

void empty_map_drawing(char **map, int map_size)
{
	int i;

	i = 0;
	while(i < map_size)
	{
		ft_memset(map[i], '.', (size_t)map_size); // здесь будет ft_memset
		i++;
	}
}

int solving(int quantity, t_tetr *tetri, char **map)
{
	int i;
	int j;

	j = 0;
	if (quantity == 0) //  может САША вообще нахер не нужен? сделать проверку указателя на next == NULL?
		return (1);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (tetri_placing(tetri, j, i, map))
			{
				tetri_drawing(j, i, map, tetri);
				quantity--;
				if (solving(quantity, &((tetri)->next), map))
					return (1);
				remove_tetri(tetri, map, j, i);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int fillit(int quantity, t_tetr *tetri)
{
	int map_size;
	char **map;

	map_size = ft_sqrt_round_up(quantity * 4);
	if (!(map = (char **)malloc(sizeof(char *) * (map_size * map_size)))) //size + 1 ??
		return (0);
	empty_map_drawing(map, map_size);
	while (!(solving(quantity, tetri, map)))
	{
		free(map);
		map_size++;
		if (!(map = (char **)malloc(sizeof(char *) * (map_size * map_size)))) //size + 1 ??
			return (0);
		empty_map_drawing(map, map_size);
	}
	return (0);
}

int tetri_placing(t_tetr *tetri, int y, int x, char **map)
{
	int i;
	int j;

	j = 0;
	// check isSafe ?
	while (j < (*tetri).height)
	{
		i = 0;
		while (i < (*tetri).width)
		{
			if (!(map[y + j][x + i]) || (map[y + j][x + i] != '.' && (*tetri).shape[j][i] != '.')) // существует ли эта клетка на карте вовсе, и если да, то что в ней, и что в тетримине
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int remove_tetri(t_tetr *tetri, char **map, int y, int x)
{
	int i;
	int j;

	j = 0;
	y -= (*tetri).height;
	x -= (*tetri).width;
	while (j < (*tetri).height)
	{
		i = 0;
		while ((*tetri).width)
		{
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (0);
}

int tetri_drawing(size_t y, size_t x, char **map, t_tetr *tetri)
{
	size_t i;
	size_t j;

	j = 0;
	while ((*tetri).shape[j])
	{
		y += j;
		i = 0;
		while ((*tetri).shape[j][i])
		{
			x += i;
			if ((*tetri).shape[j][i] != '.' && ((*tetri).shape[j][i] != '\n')) // and  != '\n'
				map[y][x] = (*tetri).shape[j][i];
			i++;
		}
		j++;
	}
	return (1); //что мне надо вернуть?
}
// int main()
// {
// 	t_tetr *tetri; // create a pointer and malloc it (check libft)
// 	if (!(tetri = (t_tetr *)malloc(sizeof(t_tetr))))
// 		return (0);
// 	tetri->height = 3;
// 	tetri->width = 2;
// 	tetri->letter = 'A';
// 	tetri->next = NULL;
// 	if (!(tetri->shape = (char **)malloc(sizeof(char) * 20)))
// 		return (0);
	// char random_array[][6] = {".##", "##."};
	// char *ptr;
	// ptr = random_array[0][0];
	// tetri->shape;
// }
