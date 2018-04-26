/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:27:51 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/26 15:08:12 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	placer(t_mino *mino, t_map *map, int i)
{
	int	n;
	int	ni;

	ni = 0;
	while ((mino->minostr)[ni])
	{
		n = mod_num(map->mapsize, to_int(mino->minostr[ni]));
		(map->mapstr)[i + n] = mino->letter;
		ni++;
	}
}

int			place_mino(t_mino *mino, t_map *map, int i)
{
	int	n;
	int	ni;
	int	counter;

	ni = 0;
	counter = 0;
	if (mino->location >= 0)
		return (0);
	while ((mino->minostr)[ni])
	{
		n = mod_num(map->mapsize, to_int(mino->minostr[ni]));
		if ((i + n) < MAP_AREA && (map->mapstr)[i + n] == '.')
			counter++;
		ni++;
	}
	if (counter == 4)
	{
		placer(mino, map, i);
		mino->location = i;
		return (1);
	}
	else
		return (0);
}
