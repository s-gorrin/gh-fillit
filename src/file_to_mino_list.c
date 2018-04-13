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

static int	file_to_str(char *file, char **minofile)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(ret = read(fd, buf, BUFF_SIZE)))
		return (0);
	*minofile = ft_strnew(ret);
	ft_memcpy(*minofile, buf, ret);
	close(fd);
	return (ret);
}

/*
** @Function: turns file into 2d char array
** @Param1: file to be read
** @Return: 2d char array of valid pieces, or NULL for invalid anything
*/

char		**file_to_mino_list(char *file)
{
	int		ret;
	int		i;
	int		j;
	char	*minofile;
	char	**mino_list;

	i = 0;
	j = 0;
	ret = file_to_str(file, &minofile);
	if (!(mino_list = (char **)malloc(sizeof(**mino_list) * ((ret / 21) + 1))))
		return (0);
	while (minofile[i] != '\0')
	{
		if (!(is_valid_mino_str(minofile, i)))
			return (0);
		if ((mino_list[j] = mino_id(minofile + i)) == NULL)
			return (0);
		i += 21;
		j++;
	}
	mino_list[j] = '\0';
	ft_strdel(&minofile);
	return (mino_list);
}
