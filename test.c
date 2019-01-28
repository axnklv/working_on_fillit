/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:22:26 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/29 00:07:49 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void it_is_error()
{
    write(1, "error\n", 6);
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
	   make_tetr(&argv[1], 4);
	return (0);
}
