/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:41:43 by creek             #+#    #+#             */
/*   Updated: 2019/02/19 00:19:48 by creek            ###   ########.fr       */
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

	i = 0;
	if (quantity == 0) //  может quantity вообще нахер не нужен? сделать проверку указателя на next == NULL?
		return (1);
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			if (tetri_placing((t_tetr *)tetris->content, j, i, map, map_size))
			{
				tetri_drawing(i, j, map, (t_tetr *)tetris->content, map_size);
				for (int n = 0; n < map_size; n++)
					printf("%s\n", map[n]);
				printf("Мапа после отрисовки выше\n");
				quantity--;
				// for (int n = 0; n < map_size; n++)
				// 	printf("%s - это строчка shape\n", ((t_tetr *)tetris->content)->shape[n]);
				if (solving(quantity, tetris->next, map, map_size))
					return (1);
				remove_tetri((t_tetr *)tetris->content, map, j, i, map_size);
        quantity++;
			}
			j++;
		}
		i++;
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
// void find_first_point(t_tetr *tetri, int *coord)
// {
//     int x_shift;
//     int y_shift;
//     y_shift = 0;
//     x_shift = 0;
//     while (y_shift < 4)
//     {
//         x_shift = 0;
//         while (x_shift < 4)
//         {
//             if ((*tetri).shape[y_shift][x_shift] == (*tetri).letter)
//                 break;
//             x_shift++;
//         }
//         if ((*tetri).shape[y_shift][x_shift] == (*tetri).letter)
//             break;
//         y_shift++;
//     }
//     coord[0] = y_shift;
//     coord[1] = x_shift;
// }
void move_tetri(t_tetr *tetri)
{
	t_tetr *temp;
	int i;
	int q;
	int l;
	int k;
	int j;

	i = 0;
	while (i < 3)
    {
		j = 0;
		while (j < 4)
    	{
			if ((*tetri).shape[i][j] == '.')
				j++;
			else
				break;
			if ((*tetri).shape[i][j] == '.' && ((*tetri).shape[i + 1][j] == '.'))
				q++;
		}
		if (j == 4)
		{
			k = 0;
			while (k < 4)
			{
				l = 0;
				while (l < 4)
				{
					(*temp).shape[k][l] = (*tetri).shape[i][j];
					(*tetri).shape[i][j] = (*tetri).shape[i+1][j];
					(*tetri).shape[i+1][j] = (*temp).shape[k][l];
					l++;
				}
				k++;
			}
		}
		if (q == 4)
		{
			k = 0;
			while (k < 4)
			{
				l = 0;
				while (l < 4)
				{
					(*temp).shape[k][l] = (*tetri).shape[i][j];
					(*tetri).shape[i][j] = (*tetri).shape[i][j+1];
					(*tetri).shape[i][j+1] = (*temp).shape[k][l];
					l++;
				}
				k++;
			}
		}
		i++;
	}
}

int tetri_placing(t_tetr *tetri,  int x, int y,char **map, int map_size)
{
	int i;
	int j;
	// printf("%d - это x_shift\n", x_shift);
	// printf("%d - это y_shift\n", y_shift);
	// printf("%d - это tetri_height\n", (*tetri).height);
	// printf("%d - это tetri_width\n", (*tetri).width);
	//move_tetri(tetri);
	printf("I m here x %5d, y %5d, mapsize %5d\n", x, y, map_size);
	if (map[y][x] != '.')
		return (0);
	// j = y_shift;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			printf("tetri i %4d, j %4d, value %c, letter %c \n", i,j,tetri->shape[i][j], tetri->letter);
			if ((tetri->shape)[i][j] == tetri->letter)
			{
				printf("args: x %4d, y %4d, i %4d, j %4d\n", x,y,i,j);
				if (!((y + i >= 0) && (y + i < map_size) && (x + j >= 0) && (x + j < map_size)))
					return (0);
				if (map[y + i][x + j] != '.')
					return(0);
			}
		}
	}

	//
	// while (j < 4)
	// {
	// 	while (i < 4)
	// 	{
	// 		if (success_point == 0)
	// 			return (1);
	// 		if (map[y][x] == '.' && (*tetri).shape[][] == (*tetri).letter)
	// 			success_point--;
	// 		i++;
	// 	}
	// 	j++;
	// }
	// // не заходит в цикл для В, возвращает 1, типа поставил
	// while ((y_shift - j) > (*tetri).height) //в этом проблема мб (j - y_shift) < height
	// while (j < (*tetri).height)
	// {										//всесто j+y_shift
	// 	// if (map[j][i] != '.')
	// 	// 	return (0);
	// 	i = 0;
	// 	while ((x_shift - i) > (*tetri).width) // возможно что-то не так вот здесь с координатами x_shift и y_shift (!!)
	// 	while (i < (*tetri).width)
	// 	{
	// 		if ((y + j) >= map_size || (x + i) >= map_size || (map[y + j][x + i] != '.' && (*tetri).shape[j + y_shift][i + x_shift] == (*tetri).letter))  // x_shift и y_shift нельзя каждый раз использовать
	// 		//if (y + (*tetri).height > map_size || (x + (*tetri).width) > map_size || ((map[y + j][x + i] != '.') && (*tetri).shape[j + y_shift][i + x_shift] == (*tetri).letter))//j + y_shift?
	// 		{
	// 			printf("тетри не встала, щас верну 0\n");
	// 			return (0);
	// 		}
	// 		i++;
	// 	}
	// 	j++;
	// }
  	printf("тетри встала, верну 1\n");
  	printf("буква tetri - %c\n", (*tetri).letter);
	printf("успешные координаты: %d - x, %d - y\n", x, y);
	printf("%c - это символ мапы с координатами\n", map[y][x]);
	printf("мапа до отрисовки ниже\n");
	for (int n = 0; n < map_size; n++)
		printf("%s\n", map[n]);
	printf("\n");

	return (1);
}

int remove_tetri(t_tetr *tetri, char **map, int y, int x, int map_size)
{
	int i;
	int j;

	j = 0;
	// y -= (*tetri).height;
	// x -= (*tetri).width;
	// while (j < (*tetri).height)
	// {
	// 	i = 0;
	// 	while (i < (*tetri).width)
	// 	{
	// 		map[j][i] = '.';
	// 		i++;
	// 	}
	// 	j++;
	// }  // вот это стирание косячное
  while (j < map_size)
  {
    i = 0;
    while (i < map_size)
    {
      if (map [j][i] == (*tetri).letter)
        map[j][i] = '.';
      i++;
    }
    j++;
  }
  printf("мапа после зачистки ниже\n");
  for (int n = 0; n < map_size; n++)
    printf("%s\n", map[n]);
	return (0);
}

int tetri_drawing(size_t y, size_t x, char **map, t_tetr *tetri, int map_size)
{
	size_t i;
	size_t j;
    int x_shift;
    int y_shift;

    j = 0;
    i = 0;
    int coord[2] = {0, 0};
    //find_first_point(tetri, coord);
    y_shift = coord[0];
    x_shift = coord[1];
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
