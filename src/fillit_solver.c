/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:15:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/23 17:06:11 by snake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_map(t_mino **mino, t_map *map, int index)
{
    if (!*mino)
        return (1);
    while (map->mapstr[index])
    {
        if (place_mino(*mino, map, index))
        {
            if (check_map(mino + 1, map, 0))
                return (1);
            else
                unplace_mino(*mino, map);
        }
        index++;
    }
    return (0);
}

void		fillit_solver(t_mino **mino, t_map *initmap)
{
    t_map *map;

    map = initmap;
	update_mapstr(ft_sqrt_cl(map->num_mino * 4), map);
	while (check_map(mino, map, 0) == 0)
		map = new_map_plus_one(map);
	ft_putstr(map->mapstr);
    fillit_cleanup(map, mino);
}
