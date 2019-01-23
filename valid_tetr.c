/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:19:03 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/23 23:39:44 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void it_is_error()
{
    ft_putendl("error");
    exit(1); //или здесь нет разницы 1 или 0?
}

int check_size(char **tetr)
{
    int x;
    int y;
    int summ;

    x = 0;
    y = 0;
    summ = 0;
    while (y < линейный_размер_карты)
    {
        while (x < линейный_размер_карты)
        {
            if (tetr[x][y] == "#")
                summ++;
            x++;
        }
        y++;
    }
    if (summ != 4)
        it_is_error();
    return (0);
}

int check_form(char **tetr)
{
    int x;
    int y;
    int form;

    x = 0;
    y = 0;
    form = 0;
    while (y < линейный_размер_карты)
    {
        while (x < линейный_размер_карты)
        {
            if (tetr[x][y] == "#")
            {
                if ((tetr[x + 1][y] != "#") && (tetr[x - 1][y] != "#") \
                && (tetr[x][y - 1] != "#") && (tetr[x][y + 1] != "#"))
                form++;
            }
            x++;
        }
        y++;
    }
    if (form > 0)
        it_is_error();
    return (0);
}

int check_content(char **tetr)
{
    int x;
    int y;
    int points;

    x = 0;
    y = 0;
    points = 0;
    while (y < линейный_размер_карты)
    {
        while (x < линейный_размер_карты)
        {
            if (tetr[x][y] == "#" || tetr[x][y] == ".")
                points++;
            x++;
        }
        y++;
    }
    if (points != 16)
        it_is_error();
    return (0);
}
