/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplace_mino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:19:49 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/16 15:46:33 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: unplaces a mino by changing its letter to a '.'
** @Param1: map that might contain the mino to be unplaced
** @Param2: letter of the mino being looked for
** @Return: 1 if the letter was unplaced, 0 if it was not found
*/

int	unplace_mino(t_map *map, int letter)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map->mapstr[i] != '\0')
	{
		if (map->mapstr[i] == letter + 'A')
		{
			map->mapstr[i] = '.';
			flag++;
		}
		i++;
	}
	return (flag == 4);
}
