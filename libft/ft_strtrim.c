/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 23:59:55 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/09 12:18:05 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_trim(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*r;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace_trim(s[start]))
		start++;
	if (!s[start])
		return (ft_strnew(0));
	while (s[end])
		end++;
	end--;
	while (ft_isspace_trim(s[end]))
		end--;
	end++;
	r = ft_strnew((end - start));
	if (!r)
		return (NULL);
	ft_strncpy(r, &s[start], end - start);
	return (r);
}
