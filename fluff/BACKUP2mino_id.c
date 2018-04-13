/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:55:27 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/09 14:43:32 by snake            ###   ########.fr       */
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
static void	one_first(char *ret, char *mstr, int i)
{
	if (mstr[i + 2] == '#')
	{
		if (mstr[i + 3] == '#')
			ret = "0123\0";
		else if (mstr[i + 5] == '#')
			ret = "0125\0";
		else if (mstr[i + 6] == '#')
			ret = "0126\0";
		else if (mstr[i + 7] == '#')
			ret = "0127\0";
	}
	else if (mstr[i + 4] == '#' && mstr[i + 5] == '#')
		ret = "1256\0";
	else if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		ret = "0156\0";
	else if (mstr[1 + 5] == '#' && mstr[i + 10] == '#')
		ret = "015A\0";
	else if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		ret = "0167\0";
	else if (mstr[1 + 6] == '#' && mstr[i + 11] == '#')
		ret = "016B\0";
	else
		ret = NULL;
}

/*
** @Function: checks for pieces where second hash is at +4
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/
static void	four_first(char *ret, char *mstr, int i)
{
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		ret = "1567\0";
	else if (mstr[i + 5] == '#' && mstr[i + 9] == '#')
		ret = "156A\0";
	else if (mstr[i + 5] == '#' && mstr[i + 10] == '#')
		ret = "156B\0";
	else
		ret = NULL;
}

/*
** @Function: checks for pieces where second hash is at +5
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/
static void	five_first(char *ret, char *mstr, int i)
{
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		ret = "0567\0";
	else if (mstr[i + 6] == '#' && mstr[i + 10] == '#')
		ret = "056A\0";
	else if (mstr[i + 6] == '#' && mstr[i + 11] == '#')
		ret = "056B\0";
	else if (mstr[i + 9] == '#' && mstr[i + 10] == '#')
		ret = "16AB\0";
	else if (mstr[i + 10] == '#' && mstr[i + 11] == '#')
		ret = "05AB\0";
	else if (mstr[i + 10] == '#' && mstr[i + 15] == '#')
		ret = "05AF\0";
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
char		*mino_id(char *minostr)
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
		ret = "2567\0";
	else if (minostr[i + 4] == '#')
		four_first(ret, minostr, i);
	else if (minostr[i + 5] == '#')
		five_first(ret, minostr, i);
	else
		return (NULL);
	return (ret);
}
