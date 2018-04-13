/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:11:43 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/02 23:09:13 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *u;

	u = (unsigned char *)s;
	if (n)
	{
		while (n--)
		{
			if (*u == (unsigned char)c)
				return ((void*)u);
			u++;
		}
	}
	return (0);
}
