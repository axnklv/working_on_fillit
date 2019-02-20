/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:41:43 by creek             #+#    #+#             */
/*   Updated: 2019/02/21 02:37:35 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solving.h"

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
	if (quantity == 0)
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

void cut_emplty_lines(t_tetr *tetri)
{
	int str_counter = 0;
	int i = 0;
	int j = 0;
	int new_i;
	while (i < 4)
	{
		j = 0;
		str_counter = 0;
		while (j < 4)
		{
			if ((*tetri).shape[i][j] == '.')
				str_counter++;
			j++;
		}
		if (str_counter == 4)
			{
        new_i = i;
        while (new_i < 3 - i)
       {
          ft_strncpy((*tetri).shape[new_i], (*tetri).shape[new_i + 1], 5);
          new_i++;
       }
       ft_strncpy((*tetri).shape[new_i], "....", 5); // not sure about this one, to be tested
			}
      i++;
    }
}

void cut_emplty_column(t_tetr *tetri)
{
	int col_counter = 0;
	int i = 0;
	int j = 0;
	int new_i = 0;
  int new_j = 0;
	while (j < 4)
	 {
		i = 0;
		col_counter = 0;
		while (i < 4)
		{
			if ((*tetri).shape[i][j] == '.')
				col_counter++;
			i++;
		}
		if (col_counter == 4)
	   {
       new_i = 0;
       while (new_i < 4)
       {
         new_j = j;
         while (new_j + 1 < 4)
         {
          (*tetri).shape[new_i][new_j] = ((*tetri).shape[new_i][new_j + 1]);
            new_j++;
         }
         (*tetri).shape[new_i][new_j] = '.';
         new_i++;
       }
     }
		j++;
  }
}

int tetri_placing(t_tetr *tetri,  int x, int y,char **map, int map_size)
{
	int i;
	int j;
	int k;
	cut_emplty_lines(tetri);
  cut_emplty_column(tetri);
	printf("ниже обрезанная тетри\n");
	for (int n = 0; n < 4; n++)
		printf("%s\n", (*tetri).shape[n]);
	printf("выше обрезанная тетри\n");
  while (1 && tetri->letter == 'B') // этот бесконечный цикл для дебага
    ;
	//printf("I m here x %5d, y %5d, mapsize %5d\n", x, y, map_size);
	if (map[y][x] != '.')
		return (0);
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((tetri->shape)[0][0] == '.' && k == 0)
			{
				k++;
			}
			printf("tetri i %4d, j %4d, value %c, letter %c \n", i,j,tetri->shape[i][j], tetri->letter);
			if ((tetri->shape)[i][j] == tetri->letter)
			{
				printf("args: x %4d, y %4d, i %4d, j %4d\n", x,y,i,j);
				if (!((y + i >= 0) && (y + i < map_size) && (x + j - k >= 0) && (x + j - k < map_size)))
					return (0);
				if (map[y + i][x + j - k] != '.')
					return(0);
			}
		}
	}
  // printf("тетри встала, верну 1\n");
  // printf("буква tetri - %c\n", (*tetri).letter);
	// printf("успешные координаты: %d - x, %d - y\n", x, y);
	// printf("%c - это символ мапы с координатами\n", map[y][x]);
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
  j = 0;
  i = 0;
	int k = 0;
	while (j < (*tetri).height && (y + j) < map_size)
	{
		i = 0;
		if ((tetri->shape)[0][0] == '.' && k == 0) // !! ensure this works with the utmost left position
		{
			k++;
		}
		while (i < (*tetri).width && (x + i) <= map_size)
		{
			if (((*tetri).shape[j][i] == (*tetri).letter) && map[y + j][x + i - k] == '.')
				map[y + j][x + i - k] = (*tetri).shape[j][i];
			i++;
		}
		j++;
	}
	return (1);
}
