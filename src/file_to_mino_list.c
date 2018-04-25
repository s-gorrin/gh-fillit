/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_mino_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:52:52 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/24 14:50:35 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: opens and reads file, memcopies to string, returns bytes read
** @Param1: file to be read
** @Param2: pointer to the string being copied to
** @Return: number of bytes read by read call
*/

/*
static void     ft_free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i] != NULL)
    {
        free(&(arr[i]));
        i++;
    }
}
*/

t_mino	**file_to_mino_list(char *filepath, int *num_mino)
{
	char	*mino_file_str;
	char	**mino_list;
    t_mino  **t_mino_list;

	mino_file_str = file_to_str(filepath);
	if (!mino_file_str)
		return (NULL);
	*num_mino = verify_input(mino_file_str);
	if (!(*num_mino))
		return (NULL);
	mino_list = minofile_minostr_check(mino_file_str, *num_mino);
    t_mino_list = get_mino_array(mino_list, *num_mino);
	ft_strdel(&mino_file_str); // THIS IS WHERE A FREE WAS ADDED
	if (t_mino_list)
		return (t_mino_list);
	else
		return (NULL);
}

char	*file_to_str(char *filepath)
{
	int		fd;
	int		ret;
	char	*minofile;
	char	buf[BUFF_SIZE + 1];

	if ((fd = open(filepath, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
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
	mino_list = (char **)malloc(num_minos + 1);
	if (!mino_list)
		return (NULL);
	while (mino_file_str[index])
	{
		tmp = mino_id(&mino_file_str[index]);
		if (!tmp)
			return (NULL);
		mino_list[mino_list_i] = tmp;
		index += MINO_STR_LEN;
		mino_list_i++;
	}
	mino_list[mino_list_i] = NULL;
	return (mino_list);
}
