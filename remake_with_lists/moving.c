/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:57:58 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/20 20:25:05 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solving.h"

void move_left(t_tetr *tetri)
{
    int i;
    int j;
    char temp;

    i = -1;
    while (++i < 4)
	{
		j = -1;
		while (++j < 3)
        {
            temp = ((*tetri).shape)[i][j];
            ((*tetri).shape)[i][j] = ((*tetri).shape)[i][j + 1];
            ((*tetri).shape)[i][j + 1] = temp;
        }
    }
}

void move_up(t_tetr *tetri)
{
    int i;
    int j;
    char temp;

    i = -1;
    while (++i < 3)
    {
        j = -1;
        while (++j < 4)
        {
            temp = ((*tetri).shape)[i][j];
            ((*tetri).shape)[i][j] = ((*tetri).shape)[i + 1][j];
            ((*tetri).shape)[i + 1][j] = temp;
        }
    }
}

void check_left(t_tetr *tetri)
{
    int i;
    int j;

    i = -1;
    while (++i < 1)
	{
		j = -1;
		while (++j < 3)
		{
            if ((tetri->shape)[i][j] == '.' && (tetri->shape)[i + 1][j] == '.'
                && (tetri->shape)[i + 2][j] == '.'
                && (tetri->shape)[i + 3][j] == '.')
                move_left(tetri);
        }
    }
}

void check_up(t_tetr *tetri)
{
    int k;
    int l;

    k = -1;
    while (++l < 1)
    {
        l = -1;
        while (++k < 3)
        {
            if ((tetri->shape)[k][l] == '.' && (tetri->shape)[k][l + 1] == '.'
                && (tetri->shape)[k][l + 2] == '.'
                && (tetri->shape)[k][l + 3] == '.')
                move_up(tetri);
        }
    }
}

void moving(t_tetr *tetri)
{
    check_left(tetri);
    check_up(tetri);
}
