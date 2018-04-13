/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:21:51 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/07 14:51:21 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	char	*save;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	r = ft_strnew(len);
	if (!r)
		return (NULL);
	save = r;
	while (*s1)
		*r++ = *s1++;
	while (*s2)
		*r++ = *s2++;
	*r = '\0';
	return (save);
}
