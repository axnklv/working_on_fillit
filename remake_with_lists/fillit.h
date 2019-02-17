/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:20:03 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/17 17:17:27 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct  s_tetr
{
    int      height;
    int      width;
    char        **shape;
    char        letter;
}               t_tetr;

char		**create_shape(char *buff, char letter);
t_list		*create_tetr(char *buff, char letter);
t_list		*read_tetris(int fd);

void	it_is_error(void);
int		check_size(char **tetr);
int		check_link(char **tetr, int x, int y);
int		check_points(char **tetr);
int		check_newline(char **tetr);
void	valid_check(char **tetr);
void	to_letters(char **tetr, char letter);
void		free_list(t_list *head);
void		ft_listadd_to_end(t_list **begin_list, t_list *new);
void        print_list(t_list *list);
int		ft_listlen(t_list *content);
void printing_fin_map(char **map);

#endif
