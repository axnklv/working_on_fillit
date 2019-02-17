/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:41:43 by creek             #+#    #+#             */
/*   Updated: 2019/02/18 02:46:28 by creek            ###   ########.fr       */
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
	while (i < map_size)
	{
		map[i] = ft_strnew((size_t)map_size + 1);
		ft_memset(map[i], '.', (size_t)map_size);
		i++;
	}
}

int solving(int quantity, t_list *tetris, char **map, int map_size)
{
	int i;
	int j;

	j = 0;
	if (quantity == 0) //  может quantity вообще нахер не нужен? сделать проверку указателя на next == NULL?
		return (1);
	while (j < map_size)
	{
		i = 0;
		while (i < map_size)
		{
			if (tetri_placing((t_tetr *)tetris->content, j, i, map, map_size))
			{
				tetri_drawing(j, i, map, (t_tetr *)tetris->content, map_size);
				for (int n = 0; n < map_size; n++)
					printf("%s\n", map[n]);
				printf("End of map\n");
				quantity--;
				// for (int n = 0; n < map_size; n++)
				// 	printf("%s - это строчка shape\n", ((t_tetr *)tetris->content)->shape[n]);
				if (solving(quantity, tetris->next, map, map_size))
					return (1);
				remove_tetri((t_tetr *)tetris->content, map, j, i);
			}
			i++;
		}
		j++;
	}
	return (0);
}

char** fillit(int quantity, t_list *tetris)
{
	int map_size;
	char **map;
	map_size = ft_sqrt_round_up(quantity * 4);
	if (!(map = (char **)malloc((sizeof(*map) * (map_size + 1))))) //size + 1 ??
		return (0);
	empty_map_drawing(map, map_size);
	while (!(solving(quantity, tetris, map, map_size)))
	{
		free(map);
		map_size++;
		if (!(map = (char **)malloc((sizeof(*map) * (map_size + 1)))))
			return (0);
		empty_map_drawing(map, map_size);
	}
	return (map);
}

int tetri_placing(t_tetr *tetri, int y, int x, char **map, int map_size)
{
	int i;
	int j;
	int x_shift;
	int y_shift;
	j = 0;
	y_shift = 0;
	x_shift = 0;
	i = 0;
	while (y_shift < 4)
	{
		x_shift = 0;
		while (x_shift < 4)
		{
			if ((*tetri).shape[y_shift][x_shift] == (*tetri).letter)
				break;
			x_shift++;
		}
		if ((*tetri).shape[y_shift][x_shift] == (*tetri).letter)
			break;
		y_shift++;
	}
	while (j + y_shift < (*tetri).height)
	{
		i = 0;
		while (i + x_shift < (*tetri).width) // возможно что-то не так вот здесь
		{
			if ((y + j) >= map_size || (x + i) >= map_size || (map[y + j][x + i] != '.' && (*tetri).shape[j + y_shift][i + x_shift] == (*tetri).letter)) // существует ли эта клетка на карте вовсе, и если да, то что в ней, и что в тетримине
			{
				printf("щас верну 0\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}
/* просто сохраню здесь старую версию своего tetri_placing */
/*int tetri_placing(t_tetr *tetri, int y, int x, char **map, int map_size)
{
	int i;
	int j;

	j = 0;
	while (j < (*tetri).height)
	{
		i = 0;
		while (i < (*tetri).width)
		{
			if ((y + j) == map_size || (x + i) == map_size || (map[y + j][x + i] != '.' && (*tetri).shape[j][i] != '.')) // существует ли эта клетка на карте вовсе, и если да, то что в ней, и что в тетримине
				return (0);
			// printf("%d - это i\n", i);
			// printf("%d - это x + i\n", x + i);
			i++;
		}
		// printf("%d - это j\n", j);
		// printf("%d - это y + j\n", y + j);
		j++;
	}
	return (1);
}*/


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
		while (i < (*tetri).width)
		{
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (0);
}

int tetri_drawing(size_t y, size_t x, char **map, t_tetr *tetri, int map_size)
{
	size_t i;
	size_t j;

	j = 0;
	int x_shift = 0;
	int y_shift = 0;
	while (y_shift < 4) // вот этот цикл надо вынести в отдельную функцию, он в другом месте тоже используется
	{
		x_shift = 0;
		while (x_shift < 4)
		{
			if ((*tetri).shape[y_shift][x_shift] == (*tetri).letter)
				break;
			x_shift++;
		}
		if ((*tetri).shape[y_shift][x_shift] == (*tetri).letter)
			break;
		y_shift++;
	}
	while (j < (*tetri).height && (y + j + y_shift) < map_size)
	{
		//y += j;
		i = 0;
		while (i < (*tetri).width && (x + i + x_shift) <= map_size)
		{
		//	x += i;
			if (((*tetri).shape[j + y_shift][i + x_shift] == (*tetri).letter) && map[y + j][x + i] == '.')//!= '.' && ((*tetri).shape[j][i] != '\n')) // and  != '\n'
				map[y + j][x + i] = (*tetri).shape[j + y_shift][i + x_shift];
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
