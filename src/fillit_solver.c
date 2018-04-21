/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:15:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/21 00:55:45 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_map(t_mino **mino, t_map *map, int index, int num_mino)
{
	int x;

	if (num_mino == map->num_mino)
		return (1);
	x = 0;
	while (x < map->num_mino) 
	{
		if (place_mino(mino[x], map, x))
		{
			if (check_map(mino, map, index + 1, num_mino + 1))
				return (1);
			else
			{
				unplace_mino(mino[x], map);
			}
		}
		++x;
	}
	return (0);
}

void		fillit_solver(char **mino_list, t_map *initmap)
{
	t_mino	**mino;
    t_map   *map;

    map = initmap;
	mino = get_mino_array(mino_list, map->num_mino);
	update_mapstr(ft_sqrt_cl(map->num_mino * 4), map);
	while (check_map(mino, map, 0, 0) == 0)
		map = new_map_plus_one(map);
	ft_putendl(map->mapstr);
}
