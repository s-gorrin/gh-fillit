/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:47:41 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/14 16:15:15 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dl;
	size_t	j;

	i = 0;
	j = 0;
	while (i < siz && dst[i] != '\0')
		i++;
	if (i == siz)
		return (ft_strlen(src) + siz);
	dl = i;
	while (src[j] != '\0' && i < siz - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dl + ft_strlen(src));
}
