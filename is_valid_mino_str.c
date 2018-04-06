/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_mino_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:57:33 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/05 19:23:39 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: checks a char mino[index] to see if it's valid, counts vars:
** hashes, chars (per line), new line characters.
** @Param1: string containing the char to be checked.
** @Param2: index of the char to be checked.
** @Return: -1 for invalidating element, 0 for valid mino, 1 for valid char.
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
			return (-1);
		chars++;
	}
	else if (mino[i] == '\n')
	{
		nls++;
		if (chars > 4)
			return (-1);
		if (nls == 4 && mino[i + 1] == '\n' && i == 19 && hashes == 4)
			return (0);
		chars = 0;
	}
	else
		return (-1);
	return (1);
}

/*
** @Function: checks to see if an input mino string is valid format, including:
** four lines of four chars, limited to '.'s and '#'s, and four total '#'s
** and five total newline characters.
** @Param1: minostring to be checked.
** @Param2: index of start of mino to be checked.
** @Return: returns 1 for valid mino format or 0 for anything invalid.
*/

int		is_valid_mino_str(char *minostr, int mindex)
{
	char	*mino;
	int	index;
	int	ret;

	mino = (char *)malloc(sizeof(*mino) * 22);
	mino = ft_strndup(minostr + mindex, 21);
	mino[21] = '\0';
	index = 0;
	ret = 0;
	while (mino[index] != '\0')
	{
		ret = char_checker(mino, index);
		if (ret < 0)
			return (0);
		else if (ret == 0)
			return (1);
		else
			index++;
	}
	return (0);
}
