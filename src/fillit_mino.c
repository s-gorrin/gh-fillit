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

t_mino	*createmino(char *minosstr, int index)
{
	t_mino	*mino;

	mino = (t_mino *)ft_memalloc(sizeof(t_mino));
	mino->minostr = minosstr;
	mino->location = -1;
	mino->letter = index + 'A';
	return (minos);
}

t_mino **get_mino_array(char **minolist)
{
	int		num_minos;
	t_mino **minoarr;
	int index;

	index = 0;
	num_minos = get_num_minos(minolist);
	minoarr = ft_memalloc(sizeof(t_mino *) * num_minos + 1);
	while (*minolist)
	{
		minoarr[index] = createmino(*minolist, index)
		*minolist++;
		index++;
	}
	minoarr[index] = NULL;
	return (minoarr);
}

int		get_num_minos(char **minosstr)
{
	int	index;

	index = 0;
	while (minosstr[index] != NULL)
		index++;
	return (index);
}
