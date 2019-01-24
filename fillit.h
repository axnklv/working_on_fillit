/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:38:46 by elchrist          #+#    #+#             */
/*   Updated: 2019/01/21 22:25:57 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //close, write, read
# include <fcntl.h> //open

void	it_is_error(void);
int		check_size(char *tetramino);
