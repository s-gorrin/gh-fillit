/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place_mino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:15:12 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/16 16:23:59 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: converts mino chars to the int values they represent
** @Param1: the char to be changed, should be a digit or letter
** @Return: positive number, or -1 if an invalid mino managed to get in
*/
/*
int	to_int(char hex)
{
	if (ft_isdigit(hex))
		return (hex - 48);
	if (hex == 'A' || hex == 'B' || hex == 'F')
		return (hex - 55);
	else
		return (-1);
}

*
** @Function: modifies number (hash location) to adjust for map size
** @Param1: map, to determine size
** @Param2: number to be modified
** @Return: modified number, which shold put the piece in the right place


int	mod_num(int line_len, int num)
{
	if (line_len == 3)
	{
		if (num >= 5 && num <= 7)
			return (num - 1);
		if (num == 10 || num == 11)
			return (num - 2);
	}
	if (line_len > 4)
	{
		if (num >= 5 && num <= 7)
			return (num + (line_len - 4));
		if (num == 10 || num == 11)
			return (num + (line_len - 3));
		if (num == 15)
			return (num + (line_len - 2));
	}
	else
		return (num);
	return (num);
}
*/
/*
** @Function: attempts to place a mino on the map, by changing the . to a letter
** @Param1: mino piece to be placed
** @Param2: map, on which to place the piece
** @Param3: index of current location on map
** @Param4: letter of piece being placed
** @Return: 1 for success, 0 for failure, -1 for invalid piece (can be removed)
*/

int			check_place_mino(const char *mino, t_map *map, int i, int letter)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;
	char *mstr;

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
