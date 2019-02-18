/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:56:24 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/18 21:35:25 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
# include "libft/includes/libft.h"
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
}

char		**create_shape(char *buff, char letter)
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

t_list		*create_tetr(char *buff, char letter)
{
	int		i;
	int		height;
	int		width;
	t_tetr	tetr;

	height = 1;
	width = 1;
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
		{
			if (buff[i + 1] == '#' && buff[i + 5] == '#' && buff[i + 6] == '#')
            {
                width = 2;
                height = 2;
                break;
            } 
			if ((i < 19) && (buff[i + 1] == '#'))
				width++;
			if ((i < 14) && (buff[i + 5] == '#'))
				height++;
		}
		i++;
	}
	tetr.height = height;
	tetr.width = width;
	tetr.letter = letter;
	tetr.shape = create_shape(buff, letter);
	return (ft_lstnew(&tetr, sizeof(t_tetr)));
}

t_list		*read_tetris(int fd)
{
	int		ret;
	char	letter;
	char	buff[22];
	t_list	*tetris;
	t_list	*tetr;

	if (fd < 0)
		it_is_error();
	tetris = NULL;
	letter = 'A';
	while ((ret = read(fd, buff, 21)) && (ret != -1))
	{
		buff[ret] = '\0';
        if ((ret != 21) && (buff[ret - 2] == '\n')) //или не ret-2, а 20 просто?
    		it_is_error();
		tetr = create_tetr(buff, letter++);
		if (tetr == NULL)
			free_list(tetris);
		ft_listadd_to_end(&tetris, tetr);
	}
	return (tetris);
}
