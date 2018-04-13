/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:50:23 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/08 01:02:19 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (ft_strlen(s) - len))
		return (NULL);
	r = ft_strnew(len);
	if (!r)
		return (NULL);
	while (i < len && s[start])
		r[i++] = s[start++];
	r[i] = '\0';
	return (r);
}
