/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:56:24 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/11 22:35:31 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		free_tetr(t_tetr *head)
{
	t_tetr	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void		ft_listadd_to_end(t_tetr **begin_list, t_tetr *new)
{
	t_tetr	*current;

	current = *begin_list;
	if (current == NULL)
		*begin_list = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_tetr		*create_tetr(char *str_tetr, char letter)
{
	int		i;
	int		point;
	t_tetr	tetr;

	point = 0;
	i = 0;
	if (str_tetr == NULL)
		it_is_error();
	while (str_tetr[i] != '\0')
	{
		if (str_tetr[i] == '#')
		{
            //придумать как считать height и weight
			// tetr.pos[point][0] = i % 5;
			// tetr.pos[point][1] = i / 5;
			tetr.letter = letter;
			point++;
		}
		i++;
	}
    //надо добавить valid_check(&tetr);
	//какой-нибудь normalize(&tetr);
	return (ft_lstnew(&tetr, sizeof(t_tetr)));
}

t_tetr		*read_tetris(int fd)
{
	int		ret;
	char	letter;
	char	buff[22];
	t_tetr	*tetris;
	t_tetr	*tetr;

	if (fd < 0)
		it_is_error();
	tetris = NULL;
	letter = 'A';
	while ((ret = read(fd, buff, 21)) && (ret != -1))
	{
		buff[ret] = '\0';
        if ((ret != 21) && (buff[ret - 2] == '\n')) //или не ret-2, а 20 просто
    		it_is_error();
		tetr = create_tetr(buff, letter++);
		if (tetr == NULL)
			free_tetr(&tetris);
		ft_listadd_to_end(&tetris, tetr);
	}
	return (tetris);
}
