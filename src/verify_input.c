/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:37:46 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/26 15:57:04 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		verify_char_counts(int dots, int hashes, int nls, int num_minos)
{
	if ((nls + 1) % MINO_STR_NL != 0)
		return (0);
	if (dots % MINO_STR_DOTS != 0 || dots != (MINO_STR_DOTS * num_minos))
		return (0);
	if (hashes % MINO_STR_HASH != 0 || hashes != (MINO_STR_HASH * num_minos))
		return (0);
	if (num_minos > MAX_MINOS || num_minos < 1)
		return (0);
	if ((hashes + dots) % ONE_PIECE != 0)
		return (0);
	return (num_minos);
}

static int		char_checker(char const *mino, int i, t_count *count)
{
	if (mino[i] == '.')
		(count->dots)++;
	else if (mino[i] == '#')
		(count->hashes)++;
	else if (mino[i] == '\n')
		(count->nls)++;
	else
		return (0);
	if (mino[i] == '\n' && (mino[i + 1] == '\0' || mino[i + 1] == '\n'))
	{
		(count->num_minos)++;
		return (verify_char_counts(count->dots, count->hashes,
			count->nls, count->num_minos));
	}
	return (-1);
}

static t_count	*count_init(void)
{
	t_count	*count;

	count = (t_count *)ft_memalloc(sizeof(t_count));
	if (!count)
		return (NULL);
	count->hashes = 0;
	count->dots = 0;
	count->nls = 0;
	count->num_minos = 0;
	return (count);
}

static int		single_mino_check(char const *mino_file_str, int index)
{
	int		end;
	t_count	*counter;

	counter = count_init();
	end = index + 20;
	while (index < end)
	{
		if (!char_checker(mino_file_str, index, counter))
			return (0);
		index++;
	}
	free(counter);
	return (1);
}

int				verify_input(char const *mino_file_str)
{
	int	index;
	int	num_mino;

	num_mino = 0;
	index = 0;
	while (mino_file_str[index])
	{
		if (!(single_mino_check(mino_file_str, index)))
			return (0);
		num_mino++;
		if (mino_file_str[index + 20] == '\n')
			index += 21;
		else if (!(mino_file_str[index + 20]))
			return (num_mino);
		else
			return (0);
	}
	return (0);
}
