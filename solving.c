/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:00:02 by creek             #+#    #+#             */
/*   Updated: 2019/01/31 17:29:19 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solving.h"
#include "libft.h"
#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tetr
{
	size_t height;
	size_t width;
	char letter;
	char **array; /* to store the actual tetrimino shape */
	struct s_tetr *next;
} t_tetr;

int	fitting_tetri(size_t height, size_t width, char **array, size_t min_size)
{
	/* допустим на вход подается массив с тетримино, в котором нет пустых строк или столбцовз
	.##.
	..#.
	..#.
	*/
	size_t i;
	size_t j;
	size_t x_shift = 0;
	size_t y_shift = 0;
	j = 0;
	char map [min_size][min_size]; // malloc
	/* min_size считается по формуле */

	while (y_shift < min_size)
	{
		y_shift += j;
		i = 0;
		while (x_shift < min_size)
		{
			x_shift += i; // x_shift тут не будет обнуляться.
			if (array[j][i] == '.') // проверяем координату тетримины
				i++;
			else if (array[j][i] == '#') // или они подаются уже окрашенными? тогда чек на не '.'
			/* если есть что вписывать, то проверяем карту */
			{
				if (map[y_shift][x_shift] == '.') /* если клетка свободна */
					i++; /* одну клетку успешно вписали, теперь проверяем следующую клетку фигуры*/
				else
				{
					/* если не вписался, то обнуляем тетримину, потому что нужно, чтобы все клетки подряд вписались */
					i = 0;
					j = 0;
				}
				x_shift++; //если клетка занята, пробуем следующую;

			}
			if (i == width - 1) // все клетки по горизонтали проверили, можно переходить к следующей строчке
				j++;
			if (x_shift == min_size - 1)
			{
				y_shift++;
				x_shift = 0;
			}
			if (i == width - 1 && j == height - 1)
				break ; // значит тетримина успешно вписалась, и можно рисовать и переходить к следующей фигуре (?)

		}
		/* если успешно вышли отсюда и фигура вместилась, то запоминаем ее на карте*/
		return (1);
	}
	return(0);
}

size_t min_map_size(size_t quantity)
{
	return(ft_sqrt(quantity * 4));
}

int main()
{
	int quantity = 1; /* для начала */

	t_tetr *tetr_a; // create a pointer and malloc it (check libft)
	if (!(tetr_a = (t_tetr *)malloc(sizeof(t_tetr))))
		return (0);
	tetr_a->height = 3;
	tetr_a->width = 2;
	tetr_a->letter = 'A';
	tetr_a->next = NULL;

	tetr_a->array = {'.', '#'};
					// {'#', '#'},
					// {'#', '.'}}; /* или надо замаллочить сначала и туда уже записать? */


	size_t min_side = min_map_size(quantity);

	printf("%d", fitting_tetri(tetr_a->height, tetr_a->width, tetr_a->array, min_side));
	return (0);
}
