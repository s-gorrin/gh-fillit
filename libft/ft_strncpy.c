/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:37:00 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/08 00:58:40 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*dstart;

	d = dst;
	s = src;
	dstart = d;
	while (len--)
	{
		if (*s)
			*d++ = *s++;
		else
			*d++ = '\0';
	}
	return (dstart);
}
