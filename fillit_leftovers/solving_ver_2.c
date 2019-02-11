/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_ver_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:07:05 by creek             #+#    #+#             */
/*   Updated: 2019/02/08 14:05:39 by creek            ###   ########.fr       */
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
	struct s_tetr *next;
	char **array; /* to store the actual tetrimino shape */
} t_tetr;

static size_t x;
static size_t y;

/* this function draws a tetrimino when it fits successfully
it's assumed that tetrimino is already coloured */

int tetri_drawing(size_t x, size_t y, char **map, char **shape, char letter)
{
	size_t i;
	size_t j;

	j = 0;
	while (shape[j])
	{
		y += j;
		i = 0;
		while (shape[j][i])
		{
			x += i;
			if (shape[j][i] != '.')
				map[y][x] = shape[j][i];
			i++;
		}
		j++;
	}
	return (1); //что мне надо вернуть?
}

/* finds the next possible position to fit tetrimino, updates coordinates */

int map_iterating(t_tetr **tetri, char **map, size_t map_size) // size_t height, size_t width, char **array - это все содержится в структуре tetri
{
	size_t i;
	size_t j;

	size_t x = 0;
	size_t y = 0;
	j = 0;
	while (y < map_size)
	{
		y += j;
		i = 0;
		while (x < map_size)
		{
			/* если есть что вписывать, то проверяем карту */
			checking_position(&i, &j, &x, &y, map);
			if (i == (tetri->width - 1) && j == (tetri->height - 1)) // на самом деле здесь сейчас будет True при проверке последней клетки тетримины
				return (1) ; // значит тетримина успешно вписалась, и можно рисовать и переходить к следующей фигуре (?)
		}
	}
	return(0); // ВАЖНО дойти сюда и возвращать ноль, если в существующей карте фигура никак не вписалась.
}

/* Здесь надо понять, какие аргументы мне надо модифицировать и возвращать обратно, а какие и так можно оставить */
int checking_position(size_t *i, size_t *j, size_t *x, size_t *y, char **map)
{
	x += i; // x_shift тут не будет обнуляться.
	if ((tetri->shape)[j][i] == '.') // проверяем координату тетримины
		i++;
	else if ((tetri->shape)[j][i] == '#') // или они подаются уже окрашенными? тогда чек на не '.'
	{
		if (map[y][x] == '.') /* если клетка свободна */
			i++; /* одну клетку успешно вписали, теперь проверяем следующую клетку фигуры*/
		else
		{
			/* если не вписался, то обнуляем тетримину, потому что нужно, чтобы все клетки подряд вписались */
			i = 0;
			j = 0;
		}
		x++; //если клетка занята, пробуем следующую;
	}
	if (i == tetri->width - 1) // все клетки по горизонтали проверили, можно переходить к следующей строчке
		j++;
	if (x == map_size - 1)
	{
		y++;
		x = 0;
	}
	return (0);
}


int fitting(size_t map_size, int quantity, t_tetr **tetri) // может ей передавать стартовые координаты?
{
	if (quantity == 0)
		return (1); //возвращает True, если дошел до конца, и все фигуры вписались
	while (map[]) // map будет объявлен в другой функции
	{
		if (map_iterating(tetri, map, map_size)) // если текущая фигура встает успешно
		{
			tetri_drawing(x, y, map, tetri->shape, tetri->letter); // мы ее рисуем
			quantity--;
			return(fitting(map_size, quantity, tetri->next->shape)); // здесь будет заходить в рекурсию бесконечно, и никогда в tetri_drawing);
		}
		else //сюда надо зайти, если конкретная фигура не вписалась, и надо попробовать следующее положение для предыдущей фигуры
		/* т.е. checking_position вернул 0 */
			return(0);//fitting(shape - 1, x + 1, y)); // тогда идем дальше со следующей фигурой	// 	quantity--;
	}
	if (конец карты && quantity > 1) // Наоборот, quantity - изначальное, т.е. мы попробовали все клетки для первой фигуры и ничего не встает
	{
		map_size++;
		return(fitting(map_size, quantity, tetri->shape));
	}
	return (0);
}

int main_fitting()
{
	char **map;
	/* incrementing map_size and calling fitting() in a loop until in returns 1 */
	while (!(fitting(map_size, quantity, tetri)))
	{
		free(map);
		map_size++;
		map = (char**)malloc(sizeof(char*) * (map_size * map_size));
	}
	return (0);
}

int		ft_sqrt(int nb)
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

int main()
{
	int quantity = 1; /* для начала */

	t_tetr *tetri; // create a pointer and malloc it (check libft)
	if (!(tetri = (t_tetr *)malloc(sizeof(t_tetr))))
		return (0);
	tetri->height = 3;
	tetri->width = 2;
	tetri->letter = 'A';
	tetri->next = NULL;
	// if (!(tetr_a->array = (char *)malloc(sizeof(char) * 10)))
	// 	return (0);
	// tetr_a->array;
	char random_array[][6] = {".##", "##."};
	char *ptr = &random_array[0][0];
	tetr_a->array = &ptr;
	size_t min_side = ft_sqrt(quantity * 4);

	printf("%d", fitting_tetri(tetri->height, tetr_a->width, tetr_a->array, min_side));
	return (0);
}
