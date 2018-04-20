/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:15:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/19 22:27:17 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_map(t_mino **mino, t_map *map, int index, int num_mino)
{
	int	next_mino = 0;

	if (num_mino == 0)
		return (1);
	if (index == MAP_AREA - 3)
		return (0);
	while (next_mino < map->num_mino)
	{
		while ((mino[next_mino])->location == -1)
		{
			if (place_mino(mino[next_mino], map, index))
				check_map(mino, map, index + 1, num_mino - 1);
			next_mino++;
		}
		while ((mino[next_mino])->location != -1)
			next_mino--;
		index = unplace_mino(mino[next_mino], map);
		check_map(mino, map, index, num_mino + 1);
	}
	return(0);
}

void		fillit_solver(char **mino_list)
{
	t_map	*map;
	t_mino	**mino;

	map = createmap(0);
	map->num_mino = ft_arrlen(mino_list);
	mino = get_mino_array(mino_list, map->num_mino);
	map = createmap(ft_sqrt_cl(map->num_mino * 4));
	while (check_map(mino, map, 0, map->num_mino) == 0)
		map = new_map_plus_one(map);
	ft_putendl(map->mapstr);
}