/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:25:34 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 14:33:06 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: converts mino chars to the int values they represent
** @Param1: the char to be changed, should be a digit or letter
** @Return: positive number, or -1 if an invalid mino managed to get in
*/

int	to_int(char hex)
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
