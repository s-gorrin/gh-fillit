/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:44:00 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/14 15:06:58 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wc(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
		count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

static size_t	len(char const *s, char c, size_t i)
{
	size_t	l;

	l = 0;
	while (s[i] != c && s[i])
	{
		i++;
		l++;
	}
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		words;
	int		tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = wc(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		tmp = len(s, c, i);
		if (s[i])
			ret[j++] = ft_strndup(s + i, tmp);
		i += tmp;
	}
	ret[j] = 0;
	return (ret);
}
