/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:19:03 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/21 22:25:55 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void it_is_error()
{
    ft_putendl("error");
    exit(1);
}

int check_size(char *tetramino)
{
    int i;
    int summ;

    i = 0;
    while (i < линейный_размер_карты)
    {
        //какие-то ещё условия
        if (tetramino[i] == "#")
            summ++;
        i++;
    }
    if (summ != 4)
        it_is_error();
}
