/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplace_mino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:19:49 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 22:47:47 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: unplaces a mino by changing its letter to a '.'
** @Param1: map that might contain the mino to be unplaced
** @Param2: letter of the mino being looked for
** @Return: 1 if the letter was unplaced, 0 if it was not found
*/

int	unplace_mino(t_mino *mino, t_map *map)
{
	int		n;
	int		ni;
	int		loc;
	int		counter;
	char	let;

	ni = 0;
	counter = 0;
	loc = mino->location;
	let = mino->letter;
	while ((mino->minostr)[ni])
	{
		n = mod_num(map->mapsize, to_int(mino->minostr[ni]));
		if ((map->mapstr)[loc + n] == let)
		{
			(map->mapstr)[loc + n] = '.';
			counter++;
		}
		ni++;
	}
	mino->location = -1;
	if (counter == 4)
		return (loc);
	else
		return (0);
}
