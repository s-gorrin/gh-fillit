/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_mino_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:52:52 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 15:48:27 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: opens and reads file, memcopies to string, returns bytes read
** @Param1: file to be read
** @Param2: pointer to the string being copied to
** @Return: number of bytes read by read call
*/

char	**file_to_mino_list(char *filepath)
{
	char	*mino_file_str;
	char	**mino_list;
	int		num_minos;

	mino_file_str = file_to_str(filepath);
	if (!mino_file_str)
		return (NULL);
	num_minos = verify_input(mino_file_str);
	if (!num_minos)
		return (NULL);
	mino_list = minofile_minostr_check(mino_file_str, num_minos);
	if (mino_list)
		return (mino_list);
	else
		return (NULL);
}

char	*file_to_str(char *filepath)
{
	int		fd;
	int		ret;
	char	*minofile;
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

char	**minofile_minostr_check(char *mino_file_str, int num_minos)
{
	char	**mino_list;
	char	*tmp;
	int		index;
	int		mino_list_i;

	index = 0;
	mino_list_i = 0;
	mino_list = (char **)ft_memalloc(num_minos + 1);
	if (!mino_list)
		return (NULL);
	while (mino_file_str[index])
	{
		tmp = minostr_check(mino_file_str, index);
		if (!tmp)
			return (NULL);
		mino_list[mino_list_i] = tmp;
		index += MINO_STR_LEN;
		mino_list_i++;
	}
	mino_list[mino_list_i] = NULL;
	return (mino_list);
}

char	*minostr_check(char *mino_file_str, int index)
{
	char	*minostart;

	minostart = &mino_file_str[index];
	return (mino_id(minostart));
}
