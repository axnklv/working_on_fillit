/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:38:46 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/11 17:53:29 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void	it_is_error(void);
int		check_size(char **tetr);
int		check_link(char **tetr, int x, int y);
int		check_points(char **tetr);
int		check_newline(char **tetr);
void	valid_check(char **tetr);
void	to_letters(char **tetr, char letter);
char	**premake_tetr(char *buff, int quantity);// char letter);
char	***make_tetr(char *argv);//, int quantity);
int     ft_quantity(int i);

#endif
