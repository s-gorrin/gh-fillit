/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:03:34 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/19 22:13:09 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: creates a t_map with a new mapstr of size
** @Param1: The size of the mapstr to be created.
** @Return: A t_map with mapstr of size, with mapsize set to size;
*/

t_map	*createmap(int size)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (map)
	{
		if (!size)
		{
			map->mapsize = 0;
			map->mapstr = NULL;
			num->minos = 0;
			return (map);
		}
		map->mapsize = size;
		map->mapstr = fill_newsquare(size);
	}
	return (map);
}

/*
** @Function: Upgrades the current size of the map by one.
** @Param1: The current map;
** @Return: The updated map;
*/

t_map	*new_map_plus_one(t_map *current_map)
{
	ft_strdel(&(current_map->mapstr));
	current_map->mapstr = fill_newsquare(current_map->mapsize + 1);
	current_map->mapsize = current_map->mapsize + 1;
	return (current_map);
}

/*
** @Function: Creates a new mapstr of size
** @Param1: The size of the mapstr
** @Return: The "fresh" map
*/

char	*fill_newsquare(int size)
{
	char	*square;
	int		i;
	int		end;

	i = 0;
	end = size * size + size;
	square = ft_strnew(end);
	while (i < end)
	{
		square[i] = '.';
		if ((i + 1) % (size + 1) == 0)
			square[i] = '\n';
		i++;
	}
	return (square);
}

/*
** @Function: Gets the length of a mapstr
** @Param1: The mapstr
** @Return: The length of the mapstr
*/

int		map_line_len(char *map)
{
	int line_len;

	line_len = 0;
	while (map[line_len] != '\n')
		line_len++;
	return (line_len);
}
