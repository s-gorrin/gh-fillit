/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:49:01 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 22:45:13 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: writes "error" to error out
** @Return: returns 0 so that it can be called in a return statement
*/

static int	ft_error(void)
{
	ft_putendl("error");
	return (0);
}

/*
** @Function: main - calls the rest of the things
** @Param1: number of arguments
** @Param2: arguments
** @Return: ft_error if error, usage if not one argument, 0 always
*/

int			main(int argc, char **argv)
{
	char	**minostr;
	int		num_mino;
	t_map	*map;

	num_mino = 0;
	map = createmap();
	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	if ((minostr = file_to_mino_list(argv[1], &num_mino)) == NULL)
		return (ft_error());
	map->num_mino = num_mino;
	fillit_solver(minostr, map);
	return (0);
}