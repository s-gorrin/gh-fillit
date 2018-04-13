/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:29:34 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/09 11:34:17 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *dst;
	char *start;

	dst = (char *)malloc(sizeof(*dst) * n + 1);
	if (dst == '\0')
		return (NULL);
	start = dst;
	while (*s1 && n--)
		*dst++ = *s1++;
	*dst = '\0';
	return (start);
}
