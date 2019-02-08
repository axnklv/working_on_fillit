/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:08:26 by creek             #+#    #+#             */
/*   Updated: 2019/02/08 03:46:06 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int some_func(int *nb)
{
	*nb += 8;
	return (0);
}

int main()
{
/*	int nb = 9;
	printf("%d\n", nb);
	some_func(&nb);
    printf("%d\n", nb);
	nb = 18;
    printf("%d\n", nb);
	some_func(&nb);
    printf("%d\n", nb); */

	int i;
    int j; // координаты фигуры тетримины
    int x;
    int y; // координаты точки на карте

    i = 0;
    j = 2;
    y += j;
	printf("%d", y);
	return (0);

}
