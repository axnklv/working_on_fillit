/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_draft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:07:05 by creek             #+#    #+#             */
/*   Updated: 2019/02/03 20:16:35 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t x;
static size_t y;




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

int checking_position()
{


	return (0);
}

int fitting(size_t map_size, int quantity, char **shape) // может ей передавать стартовые координаты?
{
	if (quantity = 0 && ПОСЛЕДНЯЯ ФИГУРА ВСТАЛА)
		return (1); //возвращает True, если дошел до конца, и все фигуры вписались
	while (карта) //
	{
		// if (checking_position(shape)) // если текущая фигура встает успешно
		// {
		// 	tetri_drawing(x, y, map, shape, letter);
		// 	quantity--;
		// 	return(fitting(SHAPE со следующей тетриминой, quantity, map_size)); // здесь будет заходить в рекурсию бесконечно, и никогда в tetri_drawing);
		// }
		// else //сюда надо зайти, если конкретная фигура не вписалась, и надо попробовать следующее положение для предыдущей фигуры
		// но тогда в if должно быть return от fitting. И понять когда фиттинг блядь возвращает ноль
		// 	{
		//
		// 	}
		if (checking_position == 1 && quantity >= 1????)
		{
			tetri_drawing(x, y, map, shape, letter);
			quantity--;
			fitting(shape + 1); // тогда идем дальше со следующей фигурой
		}
		else () // фигура не вписалась, чекинг позишн вернул 0
			fitting(shape - 1, x + 1, y); // тогда идем дальше со следующей фигурой
	}
	if (конец карты) // ????
		map_size++;
	return (0);
}
