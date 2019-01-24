/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:45:08 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/24 20:23:42 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int reading_tetras(int fd)
// {
//     int ret;
//     char *tetr;
//
//     while (ret = read(fd, tetr, 21) > 0)
//     {
//         tetr[ret] = '\n';
//         if (valid_check(tetr) || quantity(summ_n) > 26)
//             it_is_error();
//     }
// }

//функция, которая будет переводить решеточки к буквам
//по моей задумке должна будет применяться в цикле, с постоянно увелич. quantity
//т.е. изначально quantity=0 => буква=А, счётчик увелич. => quantity=1, буква=B
void	to_letters(char **tetr, int quantity)
{
	int i;
	int j;

	i = 0;
	while (tetr[i] != NULL)
	{
		j = 0;
		while (tetr[i][j])
		{
			 if (tetr[i][j] == '#')
				tetr[i][j] = 65 + quantity;
            j++;
		}
        i++;
	}
}

//просто разбиение make_tetr на 2 функции, т.к. в норму не запихнуть
//тут и так код ублюдский с этими внутренними инкрементами
char	**premake_tetr(char *buff, int quantity)
{
	char	**temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(temp = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	temp[4] = NULL; // temp[4] = '\n'
	while (i < 4)
	{
		if (!(temp[i] = (char*)malloc(5)))
			return (NULL);
		j = 0;
		while (j < 4)
			temp[i][j++] = buff[k++];//buff iz make tetr, v nego chitautsya tetr
		temp[i++][j] = '\0';
		k++;
	}
	valid_check(temp);
	to_letters(temp, quantity);
	return (temp);
}

//потом будет в void fillit
//наверное что-то в духе tetr = make_tetr(argv, quantity)
//21 символ т.к. 5х4=20 + 1 символ '\n' между тетраминосами
//22 т.к. в буфер закидывается конец
char	***make_tetr(char *argv, int quantity)
{
	char	***tetr;
	char	buff[22];
	int		ret;
	int		fd;
	int		i;

	i = 0;
	if (!(tetr = (char***)malloc(sizeof(char**) * (quantity + 1))))
		return (NULL);
	tetr[quantity] = NULL;
	while ((ret = read(fd, buff, 21)) && (i < 27))
	{
		buff[ret] = '\0';
		if (ret != 21 && buff[ret - 2] == '\n')
			it_is_error();
		tetr[i] = premake_tetr(buff, i);
        i++;
	}
	return (tetr);
}
