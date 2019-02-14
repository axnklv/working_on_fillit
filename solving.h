/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:31:04 by creek             #+#    #+#             */
/*   Updated: 2019/02/11 22:30:10 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

typedef struct  s_tetr
{
    int      height;
    int      width;
    char        **shape;
    char        letter;
    struct s_tetr *next;
}               t_tetr;

void	ft_listadd_to_end(t_tetr **begin_list, t_tetr *new);
void		free_tetr(t_tetr *head);

int	ft_sqrt(int nb);

void empty_map_drawing(char **map, int min_size);

int map(int quantity);

int fitting(char **map, t_tetr **tetri, int map_size, int quantity);

int map_iterating(t_tetr **tetri, char **map, int map_size);

int tetri_drawing(size_t x, size_t y, char **map, char **shape);//, char letter);
