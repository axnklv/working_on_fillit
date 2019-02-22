/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:23:39 by creek             #+#    #+#             */
/*   Updated: 2019/02/22 20:21:35 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solving.h"

void	cut_empty_lines(t_tetr *tetri)
{
	int str_counter;
	int i;
	int j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		str_counter = 0;
		while (++j < 4)
		{
			if ((*tetri).shape[0][j] == '.')
				str_counter++;
		}
		if (str_counter == 4)
		{
			j = 0;
			while (j < 3)
			{
				ft_strncpy((*tetri).shape[j], (*tetri).shape[j + 1], 5);
				j++;
			}
			ft_strncpy((*tetri).shape[3], "....", 5);
		}
	}
}

void	column_cutting(t_tetr *tetri)
{
	int new_i;
	int new_j;

	new_i = 0;
	while (new_i < 4)
	{
		new_j = 0;
		while (new_j < 3)
		{
			(*tetri).shape[new_i][new_j] = ((*tetri).shape[new_i][new_j + 1]);
			new_j++;
		}
		(*tetri).shape[new_i][3] = '.';
		new_i++;
	}
}

void	cut_empty_column(t_tetr *tetri)
{
	int col_counter;
	int i;
	int j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		col_counter = 0;
		while (i < 4)
		{
			if ((*tetri).shape[i][0] == '.')
				col_counter++;
			i++;
		}
		if (col_counter == 4)
			column_cutting(tetri);
		j++;
	}
}

int		tetri_placing(t_tetr *tetri, int x, int y, char **map, int map_size)
{
	int i;
	int j;
	int k;

	cut_empty_lines(tetri);
	cut_empty_column(tetri);
	if (map[y][x] != '.')
		return (0);
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((tetri->shape)[0][0] == '.' && k == 0 && x != 0)
			{
				k++;
				if (stupid_func(tetri))
					k++;
			}
			if ((tetri->shape)[i][j] == tetri->letter)
			{
				if (!((y + i >= 0) && (y + i < map_size) && (x + j - k >= 0)\
				&& (x + j - k < map_size)))
					return (0);
				if (map[y + i][x + j - k] != '.')
					return (0);
			}
		}
	}
	return (1);
}

int		remove_tetri(t_tetr *tetri, char **map, int y, int x, int map_size)
{
	int i;
	int j;

	j = 0;
	while (j < map_size)
	{
		i = 0;
		while (i < map_size)
		{
			if (map[j][i] == (*tetri).letter)
				map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (0);
}

int		tetri_drawing(size_t y, size_t x, char **map, t_tetr *tetri, int map_size)
{
	size_t		i;
	size_t		j;
	int			k;

	j = 0;
	k = 0;
	while (j < (*tetri).height && (y + j) < map_size)
	{
		i = 0;
		if ((tetri->shape)[0][0] == '.' && k == 0 && x != 0)
		{
			k++;
			if (stupid_func(tetri))
				k++;
		}
		while (i < (*tetri).width && (x + i - k) <= map_size)
		{
			if (((*tetri).shape[j][i] == (*tetri).letter) && map[y + j]\
			[x + i - k] == '.')
				map[y + j][x + i - k] = (*tetri).shape[j][i];
			i++;
		}
		j++;
	}
	return (1);
}
