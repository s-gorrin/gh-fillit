/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 12:19:33 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/05 23:48:27 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n_len;

	n_len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			if (!ft_strncmp(haystack, needle, n_len))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
