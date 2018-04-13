/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:07:20 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/07 14:18:34 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *r;
	char *save;

	if (!s || !f)
		return (NULL);
	r = ft_strnew(ft_strlen(s));
	if (!r)
		return (NULL);
	save = r;
	while (*s)
		*r++ = f(*s++);
	*r = '\0';
	return (save);
}
