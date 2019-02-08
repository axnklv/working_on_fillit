/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:31:04 by creek             #+#    #+#             */
/*   Updated: 2019/02/08 16:28:16 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

typedef struct  s_tetr
{
    size_t      height;
    size_t      width;
    char        **shape;
    char        letter;
    struct s_tetr *next;
}               t_tetr;

int	ft_sqrt(int nb);

void empty_map_drawing(char **map, int min_size);

int map(int quantity);

int fitting(char **map, t_tetr **tetri, int map_size, int quantity);

int map_iterating(t_tetr **tetri, char **map, int map_size);

int tetri_drawing(size_t x, size_t y, char **map, char **shape);//, char letter);
