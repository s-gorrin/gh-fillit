/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_mino.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:59:30 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 16:00:06 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_minos	*createminos(char **minosstr)
{
	t_minos	*minos;

	minos = (t_minos *)ft_memalloc(sizeof(t_minos));
	minos->minolist = minosstr;
	minos->num_mino = get_num_minos(minosstr);
	return (minos);
}

int		get_num_minos(char **minosstr)
{
	int	index;

	index = 0;
	while (minosstr[index] != NULL)
		index++;
	return (index);
}
