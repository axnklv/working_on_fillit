/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_draft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:07:05 by creek             #+#    #+#             */
/*   Updated: 2019/02/07 16:56:58 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int checking_position(size_t height, size_t width, char **array, size_t min_size) // min_size будет current_map_size
{
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
				// здесь должен быть рекурсивный вызов функции и return (1)

		}
		/* если успешно вышли отсюда и фигура вместилась, то запоминаем ее на карте*/
		return (1);
	}
	return(0); // ВАЖНО дойти сюда и возвращать ноль, если в существующей карте фигура никак не вписалась.
}

/* checking_position должен принимать только конкретную координату, и конкретную форму.
По сути эту функцию в ее виде сейчас можно разбить на две.
Хождение по клеткам будет в одной функции, внутри которой я буду вызывать другую, которая будет проверять конкретную координату.
 */

int fitting(size_t map_size, int quantity, char **shape) // может ей передавать стартовые координаты?
{
	if (quantity == 0)
		return (1); //возвращает True, если дошел до конца, и все фигуры вписались
	while (map[]) // map будет объявлен в другой функции
	{
		if (checking_position(shape)) // если текущая фигура встает успешно
		{
			tetri_drawing(x, y, map, shape, letter); // мы ее рисуем
			quantity--;
			return(fitting(SHAPE со следующей тетриминой, quantity, map_size)); // здесь будет заходить в рекурсию бесконечно, и никогда в tetri_drawing);
		}
		else //сюда надо зайти, если конкретная фигура не вписалась, и надо попробовать следующее положение для предыдущей фигуры
		/* т.е. checking_position вернул 0 */
			return(fitting(shape - 1, x + 1, y)); // тогда идем дальше со следующей фигурой	// 	quantity--;
	}
	if (конец карты && quantity > 1) // Наоборот, quantity - изначальное, т.е. мы попробовали все клетки для первой фигуры и ничего не встает
	{
		map_size++;
		return(fitting(map_size, quantity, shape));
	}
	return (0);
}
