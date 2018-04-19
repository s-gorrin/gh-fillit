/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place_mino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:15:12 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 15:49:56 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: attempts to place a mino on the map, by changing the . to a letter
** @Param1: mino piece to be placed
** @Param2: map, on which to place the piece
** @Param3: index of current location on map
** @Param4: letter of piece being placed
** @Return: 1 for success, 0 for failure, -1 for invalid piece (can be removed)
*/

int	check_place_mino(const char *mino, t_map *map, int i, int letter)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;
	char	*mstr;

	mstr = map->mapstr;
	if (ft_strchr(map->mapstr, letter + 'A'))
		return (0);
	n1 = mod_num(map->mapsize, to_int(mino[0]));
	n2 = mod_num(map->mapsize, to_int(mino[1]));
	n3 = mod_num(map->mapsize, to_int(mino[2]));
	n4 = mod_num(map->mapsize, to_int(mino[3]));
	if (n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0)
		return (-1);
	if (mstr[i + n1] == '.' && mstr[i + n2] == '.' &&
			mstr[i + n3] == '.' && mstr[i + n4] == '.')
		return (1);
	else
		return (0);
}
