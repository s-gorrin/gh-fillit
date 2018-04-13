/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:29:34 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/05 19:11:51 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dst;
	char *start;

	dst = (char *)malloc(sizeof(*dst) * ft_strlen(s1) + 1);
	if (dst == '\0')
		return (NULL);
	start = dst;
	while (*s1)
		*dst++ = *s1++;
	*dst = '\0';
	return (start);
}
