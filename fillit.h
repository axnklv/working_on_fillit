/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:38:46 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/24 20:28:24 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //close, write, read
# include <fcntl.h> //open

void	it_is_error(void);
int		check_size(char **tetr);
int		check_form(char **tetr);
int		check_points(char **tetr);
void	valid_check(char **tetr);
void	to_letters(char **tetr, int quantity);
char	**premake_tetr(char *buff, int quantity);
char	***make_tetr(char *argv, int quantity);
void	fillit(char **argv) //мб char *argv, т.к. я вызываю только argv[1]
