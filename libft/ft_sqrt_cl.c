/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_cl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:46:35 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 22:54:46 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt_cl(int nb)
{
	int	root;
	int	square;

	root = 1;
	square = 0;
	while (root <= nb / 2)
	{
		square = root * root;
		if (square >= nb)
			return (root);
		root++;
	}
	return (0);
}
