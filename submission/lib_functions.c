/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:35:08 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/21 16:29:50 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	unsigned char	p;

	d = b;
	p = c;
	while (len > 0)
	{
		*d = p;
		d++;
		len--;
	}
	return (b);
}

void				*ft_memalloc(size_t size)
{
	void			*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	else
		return (ft_memset(mem, 0, size));
}

void				ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	while (n > 0)
	{
		a[i] = b[i];
		i++;
		n--;
	}
	return (a);
}
