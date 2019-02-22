/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:31:04 by creek             #+#    #+#             */
/*   Updated: 2019/02/22 22:08:23 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int ft_sqrt_round_up(int nb);

void empty_map_drawing(char **map, int map_size);

int solving(int quantity, t_list *tetris, char **map, int map_size);

char** fillit(int quantity, t_list *tetris);

void cut_empty_lines(t_tetr *tetri);

void cut_empty_column(t_tetr *tetri);

int		tetri_placing(t_tetr *tetri, int *yx, char **map, int map_size);

int		left_corner_check(t_tetr *tetri, int *yx);

int remove_tetri(t_tetr *tetri, char **map, int map_size);

int		tetri_drawing(int *yx, char **map, t_tetr *tetri, int map_size);
