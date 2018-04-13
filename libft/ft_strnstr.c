/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:47:50 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/09 12:09:42 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	size_t n_len;
	size_t length;

	length = len;
	n_len = ft_strlen(ned);
	if (*ned == 0)
		return ((char *)hay);
	while (*hay && length > 0)
	{
		if (*hay == *ned)
			if (n_len <= length)
				if (!ft_strncmp(hay, ned, n_len))
					return ((char *)hay);
		hay++;
		length--;
	}
	return (NULL);
}
