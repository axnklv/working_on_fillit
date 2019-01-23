/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:45:08 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/23 23:45:16 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int reading_tetras(int fd)
{
    int ret;
    char letter;

    while (ret = read(fd, buff, BUFF_SIZE))
    {
        buff[ret] = '\0';
        if (check_size(tetr) || check_form(tetr) || check_content(tetr)
            || quantity(summ_n) > 26)
            it_is_error();
    }
}
