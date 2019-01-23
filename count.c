/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:55:54 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/23 23:55:01 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//ЭТА СУКА ДАЁТ СЕГФОЛТ

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*buff;
	int i;
	int summ;
	int ret;

	summ = 0;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, buff, 250);
		buff[ret] = '\0';
	}
	while (buff[i])
	{
		if (buff[i] == '\n')
			summ++;
		i++;
	}
    if (summ < 24)
        printf ("%d\n", (summ / 4));
    if ((summ > 23) && (summ < 44))
        printf ("%d\n", (summ / 4) - 1);
    if ((summ > 43) && (summ < 64))
        printf ("%d\n", (summ / 4) - 2);
    if ((summ > 63) && (summ < 84))
        printf ("%d\n", (summ / 4) - 3);
    if ((summ > 83) && (summ < 104))
        printf ("%d\n", (summ / 4) - 4);
    if ((summ > 103) && (summ < 124))
        printf ("%d\n", (summ / 4) - 5);
    if ((summ > 123) && (summ < 130))
        printf ("%d\n", (summ / 4) - 6);
}
