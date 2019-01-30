/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:45:08 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/30 23:20:49 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	to_letters(char **tetr, char letter)
{
	int i;
	int j;

	i = 0;
	while (tetr[i] != NULL)
	{
		j = 0;
		while (tetr[i][j] != '\0')
		{
			if (tetr[i][j] == '#')
				tetr[i][j] = letter;
            j++;
		}
        i++;
	}
	letter++;
}


char	**premake_tetr(char *buff, char letter)
{
	char	**temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(temp = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	temp[4] = NULL;
	while (i < 4)
	{
		if (!(temp[i] = (char*)malloc(5)))
			return (NULL);
		j = 0;
		while (j < 4)
			temp[i][j++] = buff[k++];
		temp[i++][j] = '\0';
		k++;
	}
	valid_check(temp);
	to_letters(temp, letter);
	return (temp);
}

char	***make_tetr(char *argv)//, int quantity)
{
	char	***tetr;
	char	buff[22];
	int		ret;
	int		fd;
	int		i;
	char letter;

	letter = 'A';
	i = 0;
	// if (!(tetr = (char***)malloc(sizeof(char**) * 0)))
	// 	return (NULL);
	// tetr[4] = NULL;
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buff, 21)) && (i < 27))
	{
		buff[ret] = '\0';
		if ((ret != 21) && (buff[ret - 2] == '\n')) //чтобы не кончалось пустой строкой
			it_is_error();
		tetr[i] = premake_tetr(buff, letter++);
		i++;
	}
	// для тестового вывода матрицы
	// int q;
	// int w;
	// for (q = 0; q < 2; q++)
	// {
	// 	for (w = 0; w < 4; w++)
	// 		printf("%s\n", tetr[q][w]);
	// 	printf("\n");
	// }
	return (tetr);
}
