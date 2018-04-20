/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_mino.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:59:30 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 22:43:30 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mino	*createmino(char *minosstr, int index)
{
	t_mino	*mino;

	mino = (t_mino *)ft_memalloc(sizeof(t_mino));
	mino->minostr = minosstr;
	mino->location = -1;
	mino->letter = index + 'A';
	return (mino);
}

t_mino **get_mino_array(char **minolist, int num_minos)
{
	t_mino **minoarr;
	int index;

	index = 0;
	minoarr = ft_memalloc(sizeof(t_mino *) * num_minos + 1);
	while (minolist[index])
	{
		minoarr[index] = createmino(*minolist, index);
		index++;
	}
	minoarr[index] = NULL;
	return (minoarr);
}
