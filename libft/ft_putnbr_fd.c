/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:50:29 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/05 16:49:18 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int num[10];
	int index;

	index = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(num[index] + '0', fd);
	}
}
