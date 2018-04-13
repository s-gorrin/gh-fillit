/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:49:01 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 19:02:49 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: main - calls the rest of the things
** @Param1: number of arguments
** @Param2: arguments
** @Return: ft_error if error, usage if not one argument, 0 always
*/

int	main(int argc, char **argv)
{
	t_mino	**minos;

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	if ((minos = file_to_mino_list(argv[1])) == NULL)
		return (ft_error());
	fillit_solver(minos);
	return (0);
}
