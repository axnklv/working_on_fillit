/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:44:33 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/23 23:55:55 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int count_n(int argc, char **argv)
{
    int summ_n;

    summ_n = 0;
    // ПОПЫТКА РЕАЛИЗАЦИИ В COUNT.C НЕ ВЫШЛА
    return (summ_n);
}

//может вообще сделать все фигуры в связном списке?
//тогда их количество = просто длина списка

int quantity(int summ_n)
{
    if (summ_n < 24)
        return (summ_n / 4);
    if ((summ_n > 23) && (summ_n < 44))
        return ((summ_n / 4) - 1);
    if ((summ_n > 43) && (summ_n < 64))
        return ((summ_n / 4) - 2);
    if ((summ_n > 63) && (summ_n < 84))
        return ((summ_n / 4) - 3);
    if ((summ_n > 83) && (summ_n < 104))
        return ((summ_n / 4) - 4);
    if ((summ_n > 103) && (summ_n < 124))
        return ((summ_n / 4) - 5);
    if ((summ_n > 123) && (summ_n < 130))
        return ((summ_n / 4) - 6);
}

int linear_map_size(quantity)
{
    int size;

    size = ft_sqrt(quantity * 4);
    return (size);
}
