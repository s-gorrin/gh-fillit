/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:55:27 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/05 21:50:02 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fillit.h"
#include <stdlib.h>

/*
** @Function: checks for pieces where second hash is at +1
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/
void	one_first(char *ret, char *mstr, int i)
{
	if (mstr[i + 2] == '#')
	{
		if (mstr[i + 3] == '#')
			ret = "\x0\x1\x2\x3\x0";
		if (mstr[i + 5] == '#')
			ret = "\x0\x1\x2\x5\x0";
		if (mstr[i + 6] == '#')
			ret = "\x0\x1\x2\x6\x0";
		if (mstr[i + 7] == '#')
			ret = "\x0\x1\x2\x7\x0";
	}
	if (mstr[i + 4] == '#' && mstr[i + 5] == '#')
		ret = "\x1\x2\x5\x6\x0";
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		ret = "\x0\x1\x5\x6\x0";
	if (mstr[1 + 5] == '#' && mstr[i + 10] == '#')
		ret = "\x0\x1\x5\xA\x0";
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		ret = "\x0\x1\x6\x7\x0";
	if (mstr[1 + 6] == '#' && mstr[i + 11] == '#')
		ret = "\x0\x1\x6\xB\x0";
	else
		ret = NULL;
}

/*
** @Function: checks for pieces where second hash is at +4
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/
void	four_first(char *ret, char *mstr, int i)
{
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		ret = "\x1\x5\x6\x7\x0";
	if (mstr[i + 5] == '#' && mstr[i + 9] == '#')
		ret = "\x1\x5\x6\xA\x0";
	if (mstr[i + 5] == '#' && mstr[i + 10] == '#')
		ret = "\x1\x5\x6\xB\x0";
	else
		ret = NULL;
}

/*
** @Function: checks for pieces where second hash is at +5
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/
void	five_first(char *ret, char *mstr, int i)
{
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		ret = "\x0\x5\x6\x7\x0";
	if (mstr[i + 6] == '#' && mstr[i + 10] == '#')
		ret = "\x0\x5\x6\xA\x0";
	if (mstr[i + 6] == '#' && mstr[i + 11] == '#')
		ret = "\x0\x5\x6\xB\x0";
	if (mstr[i + 9] == '#' && mstr[i + 10] == '#')
		ret = "\x1\x6\xA\xB\x0";
	if (mstr[i + 10] == '#' && mstr[i + 11] == '#')
		ret = "\x0\x5\xA\xB\x0";
	if (mstr[i + 10] == '#' && mstr[i + 15] == '#')
		ret = "\x0\x5\xA\xF\x0";
	else
		ret = NULL;
}

/*
** @Function:
** Each possible piece is hard coded in as offsets from first '#' that is found.
** They are pushed out to different functions to pass Norminette.
** @Param1: mino string to be identified.
** @Return: a char *str of hex numbers, or NULL for invalid piece/malloc fail.
** Return is formatted with the top left corner of the mino as place 0.
*/
char	*mino_id(char *minostr)
{
	int	i;
	char	*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(*ret) * 5)))
		return (NULL);
	while (minostr[i] != '#')
		i++;
	if (minostr[i + 1] == '#')
		one_first(ret, minostr, i);
	else if (minostr[i + 3] == '#')
		ret = "\x2\x5\x6\x7\x0";
	else if (minostr[i + 4] == '#')
		four_first(ret, minostr, i);
	else if (minostr[i + 5] == '#')
		five_first(ret, minostr, i);
	else
		return (NULL);
	return (ret);
}
