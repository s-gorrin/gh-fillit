/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:27:51 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 20:15:53 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	place_mino(t_mino *mino, t_map *map, int i)
{
	int		n;
	int		ni;

	ni = 0;
	counter = 0;
	if (ft_strchr(map->mapstr, mino->letter))
		return (0);
	while ((mino->minostr)[ni])
	{
		n = mod_num(map->mapsize, to_int(mino->minostr[ni]));
		if ((map->mapstr)[i + n] == '.')
		{
			(map->mapstr)[i + n] = mino->letter;
			counter++;
		}
		ni++;
	}
	if (counter = 4)
	{
		mino->location = i;
		return (1);
	}
	else
		return (0);
}
