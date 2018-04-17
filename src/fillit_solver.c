/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:15:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/16 16:59:38 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				fillit_cleanup(t_minos *minos, t_map *map)
{
	if (minos)
	{
		ft_strdel(minos->minolist);
		free(minos);
	}
	if (map)
	{
		ft_strdel(&(map->mapstr));
		free(map);
	}
}

int fillit_solve(t_minos *minos, t_map *map, size_t index, int next_mino)
{
    if (!map)
        map = createmap(ft_sqrt_cl(minos->num_mino * 4));
    if (index == ft_strlen(map->mapstr))
    {
        if (next_mino == minos->num_mino)
        {
            ft_putendl(map->mapstr);
            fillit_cleanup(minos, map);
            return (1);
        }
        map = new_map_plus_one(map);
        fillit_solve(minos, map, 0, 0);
    }
    if (!check_place_mino(minos->minolist[next_mino], map, index, next_mino))
    {
        if (index % map->mapsize == 0)
        {
            if (fillit_solve(minos, map, index + 2, next_mino))
                return (1);
        }
        else
        {
            if (fillit_solve(minos, map, index + 1, next_mino))
                return (1);
        }
        return (0);
    }
    for (; next_mino < minos->num_mino; next_mino++)
    {
        if (place_mino(minos->minolist[next_mino], map, index, next_mino))
        {
            if (index % map->mapsize == 0)
            {
                if (fillit_solve(minos, map, index + 2, next_mino + 1))
                    return (1);
            }
            else
            {
                if (fillit_solve(minos, map, index + 1, next_mino + 1))
                    return (1);
            }
            unplace_mino(map, next_mino);
        }
    }
    return (0);
}
