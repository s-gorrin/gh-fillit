/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:47:58 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/05 23:33:10 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *save;

	save = s;
	while (*s)
		s++;
	if (c == 0)
		return ((char *)s);
	while (*s != c && s != save)
		s--;
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}
