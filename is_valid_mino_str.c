/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_mino_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:57:33 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/04 15:57:41 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	char_checker(char *mino, int index)
{
	static int	hashes;
	static int	chars;
	static int	nls;

	if (mino[index] == '.')
		chars++;
	else if (mino[index] == '#')
	{
		hashes++;
		if (hashes > 4)
			return (-1);
		chars++;
	}
	else if (mino[index] == '\n')
	{
		nls++;
		if (chars > 4)
			return (-1);
		if (nls == 4 && mino[index + 1] == '\n' && index == 20)
			return (0);
		chars = 0;
	}
	else
		return (-1);
	return (1);
}

/*
** This is basically the same as the function in fill_etc.
** It has been edited for clarity (to me, I guess) and to pass Norminette.
*/

int		is_valid_mino_str(char *minostr, int mindex)
{
	char	*mino;
	int	index;
	int	ret;

	mino = &minostr[mindex];
	zero_vars(&hashes, &chars, &nls, &index);
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
}
/*
This was the first condensing rewrite before I sent it out to the static function
I'm keeing it for now just in case.
		if (mino[index] == '.')
			chars++;
		else if (mino[index] == '#')
		{
			hashes++;
			if (hashes > 4)
				return (0);
			chars++;
		}
		else if (mino[index] == '\n')
		{
			nls++;
			if (chars > 4)
				return (0);
			if (nls == 4 && mino[index + 1] == '\n' && index == 20)
				return (1);
			chars = 0;
		}
		else
			return (0);
*/

