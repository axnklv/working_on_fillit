/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:19:30 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/28 22:44:05 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void it_is_error()
{
    ft_putendl("error");
    exit(1);
}

void fillit(char **argv) //мб char *argv, т.к. я вызываю только argv[1]
{


}

int main(int argc, char **argv)
{
    if (argc == 2)
        fillit(argv[1]);
    return (0);
}
