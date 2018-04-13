/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:55:07 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/09 12:17:43 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strrev(char *str)
{
	int		dec;
	int		inc;
	char	tmp;

	dec = 0;
	inc = 0;
	if (*str == '-')
		inc = 1;
	while (str[dec] != '\0')
		dec++;
	dec -= 1;
	while (inc < dec)
	{
		tmp = str[inc];
		str[inc] = str[dec];
		str[dec] = tmp;
		inc++;
		dec--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*num;
	char	*save;
	int		malmod;

	malmod = n < 0 ? 2 : 1;
	if (n == 0)
		return ((num = ft_strdup("0")));
	if (n == -2147483648)
		return ((num = ft_strdup("-2147483648")));
	if (!(num = (char *)malloc(sizeof(*num) * ft_numlen(n) + malmod)))
		return (NULL);
	save = num;
	if (n < 0)
	{
		*num++ = '-';
		n *= -1;
	}
	while (n != 0)
	{
		*num++ = (n % 10) + '0';
		n /= 10;
	}
	*num = '\0';
	num = save;
	return (strrev(num));
}
