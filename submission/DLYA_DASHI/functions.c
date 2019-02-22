/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:35:08 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/22 20:21:16 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_vars(int *arr)
{
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = -1;
}

void	add_to_struct(t_tetr tetr, int *arr, char letter, char *buff)
{
	tetr.width = arr[0];
	tetr.height = arr[1];
	tetr.letter = letter;
	tetr.shape = create_shape(buff, letter);
}

void	usage(void)
{
	write(1, "usage: ./fillit <FILE>\n", 23);
	exit(0);
}

void	it_is_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}
