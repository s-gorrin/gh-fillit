/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_mino_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:57:33 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 17:45:54 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Libraries used:
** #include <unistd.h>
** #include <string.h>
** #include <stdlib.h>
*/
/*
** @Function: checks a char mino[index] to see if it's valid, counts vars:
** hashes, chars (per line), new line characters.
** @Param1: string containing the char to be checked.
** @Param2: index of the char to be checked.
** @Return: 0 for invalidating element, 1 for valid mino, 2 for valid char.
*/

static int	char_checker(char *mino, int i)
{
	static int	hashes;
	static int	chars;
	static int	nls;

	if (mino[i] == '.')
		chars++;
	else if (mino[i] == '#')
	{
		hashes++;
		if (hashes > 4)
			return (0);
		chars++;
	}
	else if (mino[i] == '\n')
	{
		nls++;
		if (chars > 4)
			return (0);
		if (nls == 4 && mino[i + 1] == '\n' && i == 19 && hashes == 4)
			return (1);
		chars = 0;
	}
	else
		return (0);
	return (2);
}

/*
** @Function: checks to see if an input mino string is valid format, including:
** four lines of four chars, limited to '.'s and '#'s, and four total '#'s
** and five total newline characters.
** @Param1: minostring to be checked.
** @Param2: index of start of mino to be checked.
** @Return: returns 1 for valid mino format or 0 for anything invalid.
*/

int			is_valid_mino_str(char const *minostr, int mindex)
{
	char	*mino;
	int		index;
	int		ret;

	mino = &minostr[mindex];
	index = 0;
	ret = 2;
	while (mino[index] != '\0' && ret == 2)
	{
		ret = char_checker(mino, index);
		index++;
	}
	return (ret == 1 ? 1 : 0);
}
