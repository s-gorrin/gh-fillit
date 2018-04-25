/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:55:27 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/24 16:06:15 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: checks for pieces where second hash is at +1
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/

static char	*one_first(char *mstr, int i)
{
	if (mstr[i + 2] == '#' && mstr[i + 3] == '#')
		return ("0123");
	if (mstr[i + 2] == '#' && mstr[i + 5] == '#')
		return ("0125");
	if (mstr[i + 2] == '#' && mstr[i + 6] == '#')
		return ("0126");
	if (mstr[i + 2] == '#' && mstr[i + 7] == '#')
		return ("0127");
	if (mstr[i + 4] == '#' && mstr[i + 5] == '#')
		return ("1256");
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		return ("0156");
	if (mstr[i + 5] == '#' && mstr[i + 10] == '#')
		return ("015A");
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		return ("0167");
	if (mstr[i + 6] == '#' && mstr[i + 11] == '#')
		return ("016B");
	else
		return (NULL);
}

/*
** @Function: checks for pieces where second hash is at +4
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/

static char	*four_first(char *mstr, int i)
{
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		return ("1567");
	if (mstr[i + 5] == '#' && mstr[i + 9] == '#')
		return ("156A");
	if (mstr[i + 5] == '#' && mstr[i + 10] == '#')
		return ("156B");
	else
		return (NULL);
}

/*
** @Function: checks for pieces where second hash is at +5
** @Param1: the string being checked.
** @Param2: index of first hash in the string.
** @Return: a string of relative # locations in hex or null for invalid.
*/

static char	*five_first(char *mstr, int i)
{
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		return ("0567");
	if (mstr[i + 6] == '#' && mstr[i + 10] == '#')
		return ("056A");
	if (mstr[i + 6] == '#' && mstr[i + 11] == '#')
		return ("056B");
	if (mstr[i + 9] == '#' && mstr[i + 10] == '#')
		return ("16AB");
	if (mstr[i + 10] == '#' && mstr[i + 11] == '#')
		return ("05AB");
	if (mstr[i + 10] == '#' && mstr[i + 15] == '#')
		return ("05AF");
	else
		return (NULL);
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
	int		i;
	char	*ret;

	i = 0;
//	if (!(ret = (char *)malloc(sizeof(*ret) * 5)))
//		return (NULL);
	ret = ft_strnew(4);
//	ret = NULL;
	while (minostr[i] != '#')
		i++;
	if (minostr[i + 1] == '#')
		ret = ft_strcpy(ret, one_first(minostr, i));
	else if (minostr[i + 3] == '#' && minostr[i + 4] == '#'
			&& minostr[i + 5] == '#')
		ret = ft_strcpy(ret, "2567");
	else if (minostr[i + 4] == '#')
		ret = ft_strcpy(ret, four_first(minostr, i));
	else if (minostr[i + 5] == '#')
		ret = ft_strcpy(ret, five_first(minostr, i));
	else
		return (NULL);
	return (ret);
}
