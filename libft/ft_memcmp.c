/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:11:41 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/05 19:02:02 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *u1;
	unsigned char *u2;

	while (n--)
	{
		u1 = (unsigned char *)str1;
		u2 = (unsigned char *)str2;
		if (*u1 != *u2)
			return (*u1 - *u2);
		str1++;
		str2++;
	}
	return (0);
}
