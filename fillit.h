/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:38:46 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/23 21:36:51 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //close, write, read
# include <fcntl.h> //open

void	it_is_error(void);
int check_size(char **tetram);
int check_form(char **tetram);
int check_content(char **tetr);
