/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:47:20 by sgorrin           #+#    #+#             */
/*   Updated: 2018/02/27 16:00:54 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int num[10];
	int index;

	index = 0;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
		ft_putchar('-');
	while (n != 0)
	{
		num[index] = n % 10;
		index++;
		n /= 10;
	}
	while (index > 0)
	{
		index--;
		if (num[index] < 0)
			num[index] *= -1;
		ft_putchar(num[index] + '0');
	}
}
