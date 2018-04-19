/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:27:51 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 15:53:54 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	place_mino(const char *mino, t_map *map, int i, int letter)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;

	if (ft_strchr(map->mapstr, letter + 'A'))
		return (0);
	n1 = mod_num(map->mapsize, to_int(mino[0]));
	n2 = mod_num(map->mapsize, to_int(mino[1]));
	n3 = mod_num(map->mapsize, to_int(mino[2]));
	n4 = mod_num(map->mapsize, to_int(mino[3]));
	if (n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0)
		return (-1);
	if ((map->mapstr)[i + n1] == '.' && (map->mapstr)[i + n2] == '.' &&
			(map->mapstr)[i + n3] == '.' && (map->mapstr)[i + n4] == '.')
	{
		(map->mapstr)[i + n1] = letter + 'A';
		(map->mapstr)[i + n2] = letter + 'A';
		(map->mapstr)[i + n3] = letter + 'A';
		(map->mapstr)[i + n4] = letter + 'A';
		return (1);
	}
	else
		return (0);
}
