/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:48:03 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/06 17:05:35 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*r;
	char	*save;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens2 = n < ft_strlen(s2) ? n : ft_strlen(s2);
	r = ft_strnew(ft_strlen(s1) + lens2);
	if (!r)
		return (NULL);
	save = r;
	while (*s1)
		*r++ = *s1++;
	while (*s2 && lens2 > 0)
	{
		*r++ = *s2++;
		lens2--;
	}
	*r = '\0';
	return (save);
}
