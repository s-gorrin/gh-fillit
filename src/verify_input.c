/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:13:00 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 15:45:06 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_count	*count_init(void)
{
	t_count *count;

	count = (t_count *)ft_memalloc(sizeof(t_count));
	count->hashes = 0;
	count->dots = 0;
	count->nls = 0;
	count->num_minos = 0;
	return (count);
}

static int		verify_char_counts(int dots, int hashes, int nls, int num_minos)
{
	if (nls % MINO_STR_NL != 0)
		return (0);
	if (dots % MINO_STR_DOTS != 0)
		return (0);
	if (hashes % MINO_STR_HASH != 0)
		return (0);
	if (num_minos > MAX_MINOS || num_minos < 1)
		return (0);
	return (num_minos);
}

/*
** @Function: checks a char mino[index] to see if it's valid, counts vars:
** hashes, chars (per line), new line characters.
** @Param1: string containing the char to be checked.
** @Param2: index of the char to be checked.
** @Return: 0 for invalidating element, 1 for valid mino, 2 for valid char.
*/

static int		char_checker(char *mino, int i, t_count *counts)
{
	if (mino[i] == '.')
		(count->dots)++;
	else if (mino[i] == '#')
		(count->hashes)++;
	else if (mino[i] == '\n')
	{
		(count->nls)++;
		if (mino[i + 1] == '\n')
			(count->num_minos)++;
	}
	else
		return (0);
	if (mino[i] == '\n' && mino[i + 1] == '\0')
		return (verify_char_counts(count->dots, count->hashes,
			count->nls, count->num_minos));
		return (-1);
}

/*
** @Function: checks to see if an input mino string is valid format, including:
** four lines of four chars, limited to '.'s and '#'s, and four total '#'s
** and five total newline characters.
** @Param1: minostring to be checked.
** @Param2: index of start of mino to be checked.
** @Return: returns 1 for valid mino format or 0 for anything invalid.
*/

int				verify_input(char const *minostr)
{
	int		index;
	int		ret;
	t_count	*count;

	index = 0;
	ret = -1;
	count = count_init();
	while (minostr[index] != '\0' && ret == -1)
	{
		ret = char_checker(mino, index, count);
		index++;
	}
	return (ret > 0 ? ret : 0);
}
