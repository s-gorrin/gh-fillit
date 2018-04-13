/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplace_mino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:19:49 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 21:23:34 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: unplaces a mino by changing its letter to a '.'
** @Param1: map that might contain the mino to be unplaced
** @Param2: letter of the mino being looked for
** @Return: 1 if the letter was unplaced, 0 if it was not found
*/

int	unplace_mino(char **map, int letter)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] == letter + 'A')
		{
			(*map)[i] = '.';
			flag++;
		}
		i++;
	}
	return (flag == 4);
}
