/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:07:28 by creek             #+#    #+#             */
/*   Updated: 2019/02/22 22:07:57 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetri_drawing(int *yx, char **map, t_tetr *tetri, int map_size)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < (*tetri).height && (yx[0] + j) < map_size)
	{
		i = 0;
		k = left_corner_check(tetri, yx);
		while (i < (*tetri).width && (yx[1] + i - k) <= map_size)
		{
			if (((*tetri).shape[j][i] == (*tetri).letter) && map[yx[0] + j]\
				[yx[1] + i - k] == '.')
				map[yx[0] + j][yx[1] + i - k] = (*tetri).shape[j][i];
			i++;
		}
		j++;
	}
	return (1);
}
