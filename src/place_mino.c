/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:27:51 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 23:11:37 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: converts mino chars to the int values they represent
** @Param1: the char to be changed, should be a digit or letter
** @Return: positive number, or -1 if an invalid mino managed to get in
*/

static int	to_int(char hex)
{
	if (ft_isdigit(hex))
		return (hex - 48);
	if (hex == 'A' || hex == 'B' || hex == 'F')
		return (hex - 55);
	else
		return (-1);
}

/*
** @Function: modifies number (hash location) to adjust for map size
** @Param1: map, to determine size
** @Param2: number to be modified
** @Return: modified number, which shold put the piece in the right place
*/

static int	mod_num(char const *map, int num)
{
	int	line_len;

	line_len = 0;
	while (map[line_len] != '\n')
		line_len++;
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
}

/*
** @Function: attempts to place a mino on the map, by changing the . to a letter
** @Param1: mino piece to be placed
** @Param2: map, on which to place the piece
** @Param3: index of current location on map
** @Param4: letter of piece being placed
** @Return: 1 for success, 0 for failure, -1 for invalid piece (can be removed)
*/

int			place_mino(char *mino, char **map, int i, int letter)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;

	if (ft_strchr(*map, letter + 'A'))
		return (0);
	n1 = mod_num((char const)*map, to_int(mino[0]));
	n2 = mod_num((char const)*map, to_int(mino[1]));
	n3 = mod_num((char const)*map, to_int(mino[2]));
	n4 = mod_num((char const)*map, to_int(mino[3]));
	if (n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0)
		return (-1);
	if ((*map)[i + n1] == '.' && (*map)[i + n2] == '.' &&
			(*map)[i + n3] == '.' && (*map)[i + n4] == '.')
	{
		(*map)[i + n1] = letter + 'A';
		(*map)[i + n2] = letter + 'A';
		(*map)[i + n3] = letter + 'A';
		(*map)[i + n4] = letter + 'A';
		return (1);
	}
	else
		return (0);
}
