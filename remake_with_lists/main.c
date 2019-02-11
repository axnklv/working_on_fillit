/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:45:07 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/11 22:28:54 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			main(int argc, char **argv)
{
	t_tetr	*tetris;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tetris = read_tetris(fd);
		fillit(tetris); //какая-нибудь итоговая функция, в которую всё собрано
		free_list(&tetris);
	}
	return (0);
}
