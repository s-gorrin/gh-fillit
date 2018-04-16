/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_mino_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:52:52 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 23:23:16 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: opens and reads file, memcopies to string, returns bytes read
** @Param1: file to be read
** @Param2: pointer to the string being copied to
** @Return: number of bytes read by read call
*/

char		**file_to_mino_list(char *filepath)
{
	char *mino_file_str;
	char **mino_list;
	int num_minos;
	
	mino_file_str = file_to_str(filepath);
	if (!mino_file_str)
		return (NULL);
	num_minos = mino_file_str_verif(mino_file_str);
	if (!num_minos)
		return (NULL);
	mino_list = minofile_minostr_check(mino_file_str, num_minos);
	if (mino_list)
		return (mino_list);
	else
		return (NULL);
}

char		*file_to_str(char *filepath)
{
	int		fd;
	int		ret;
	char 	*minofile;
	char	buf[BUFF_SIZE + 1];

	if (!(fd = open(filepath, O_RDONLY)))
		return (NULL);
	if (!(ret = read(fd, buf, BUFF_SIZE)))
		return (NULL);
	minofile = ft_strnew(ret);
	ft_memcpy(minofile, buf, ret);
	close(fd);
	return (minofile);
}

int			mino_file_str_verif(char *mino_file_str)
{
	int hashes;
	int nls;
	int num_minos;
	int dots;

	hashes = 0;
	nls = 0;
	num_minos = 0;
	dots = 0;
	while (*mino_file_str)
	{
		if (*mino_file_str == '#')
			hashes++;
		else if (*mino_file_str == '\n')
		{
			if (*(mino_file_str + 1) == '\n')
				num_minos++;
			nls++;
		}
		else if (*mino_file_str == '.')
			dots++;
		else
			return (0);
		mino_file_str++;
	}
	if (!(verify_char_counts(dots, hashes, nls, num_minos)))
		return (0);
	return (num_minos);
}

int			verify_char_counts(int dots, int hashes, int nls, int num_minos)
{
	if (nls % MINO_STR_NL != 0)
		return (0);
	if (dots % MINO_STR_DOTS != 0)
		return (0);
	if (hashes % MINO_STR_HASH != 0)
		return (0);
	if (num_minos > MINO_STR_LEN || num_minos < 1)
		return (0);
	// if ((nls + dots + hashes) % MINO_STR_LEN)
	// 	return (0);
	return (1);
}

char 		**minofile_minostr_check(char *mino_file_str, int num_minos)
{
	char **mino_list;
	char *tmp;
	char *tmp2;
	int index;
	int mino_list_i;

	index = 0;
	mino_list_i = 0;
	mino_list = (char **)ft_memalloc(num_minos + 1);
	if (!mino_list)
		return (NULL);
	while (mino_file_str[index])
	{
		tmp = minostr_check(mino_file_str, index);
		if (!tmp)
		{
			//free up stuff?
			return (NULL);
		}
		tmp2 = ft_strnew(4);
		ft_strlcpy(tmp2, tmp, 4);
		mino_list[mino_list_i] = tmp2;
		if (mino_list[mino_list_i] )
		index += MINO_STR_LEN;
		mino_list_i++;
	}
	mino_list[mino_list_i] = NULL;
	return (mino_list);
}

char *minostr_check(char *mino_file_str, int index)
{
	char *minostart;
	int first_hash;

	first_hash = 0;
	minostart = &mino_file_str[index];
	return (mino_id(minostart));
}