/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:31:04 by creek             #+#    #+#             */
/*   Updated: 2019/02/18 09:45:27 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

// typedef struct  s_tetr
// {
//     int      height;
//     int      width;
//     char        **shape;
//     char        letter;
//   struct s_tetr *next;
// }               t_tetr;

// void	ft_listadd_to_end(t_tetr **begin_list, t_tetr *new);
void		free_tetr(t_list *head);

int ft_sqrt_round_up(int nb);

void empty_map_drawing(char **map, int map_size);

char **fillit(int quantity, t_list *tetris);

//int fitting(char **map, t_tetr **tetri, int map_size, int quantity);

// int map_iterating(t_tetr *tetri, char **map, int map_size);

int tetri_drawing(size_t y, size_t x, char **map, t_tetr *tetri, int map_size);

//int tetri_placing(t_tetr *tetri, int y, int x, char **map);
int tetri_placing(t_tetr *tetri, int y, int x, char **map, int map_size);

int remove_tetri(t_tetr *tetri, char **map, int y, int x, int map_size);
