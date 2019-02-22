/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:31:04 by creek             #+#    #+#             */
/*   Updated: 2019/02/22 19:25:34 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"


void		free_tetr(t_list *head);

int ft_sqrt_round_up(int nb);

void empty_map_drawing(char **map, int map_size);

int solving(int quantity, t_list *tetris, char **map, int map_size);

char** fillit(int quantity, t_list *tetris);

void cut_empty_lines(t_tetr *tetri);

void cut_empty_column(t_tetr *tetri);

int tetri_placing(t_tetr *tetri,  int x, int y,char **map, int map_size);

int stupid_func(t_tetr *tetri);

int remove_tetri(t_tetr *tetri, char **map, int y, int x, int map_size);

int tetri_drawing(size_t y, size_t x, char **map, t_tetr *tetri, int map_size);
