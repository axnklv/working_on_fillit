/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:20:03 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/22 20:29:59 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_tetr
{
	int			height;
	int			width;
	char		**shape;
	char		letter;
}				t_tetr;

char			**create_shape(char *buff, char letter);
t_list			*create_tetr(char *buff, char letter);
t_list			*read_tetris(int fd);
int				check_size(char **tetr);
int				check_link(char **tetr, int x, int y);
int				check_points(char **tetr);
int				check_newline(char **tetr);
int				ft_listlen(t_list *content);
int				ft_sqrt_round_up(int nb);
int				tetri_placing(t_tetr *t, int y, int x, char **map, int m_size);
int				remove_tetri(t_tetr *t, char **map, int y, int x, int m_size);
int				stupid_func(t_tetr *tetri);
int				tetri_drawing(size_t y, size_t x, char **m, t_tetr *t, int m_s);
void			valid_check(char **tetr);
void			to_letters(char **tetr, char letter);
void			free_list(t_list *head);
void			ft_listadd_to_end(t_list **begin_list, t_list *new);
void			print_list(t_list *list);
void			printing_fin_map(char **map);
void			init_vars(int *ar);
void			add_to_struct(t_tetr tetr, int *arr, char letter, char *buff);
void			free_tetr(t_list *head);
void			empty_map_drawing(char **map, int map_size);
void			it_is_error(void);
void			usage(void);
char			**fillit(int quantity, t_list *tetris);

#endif
