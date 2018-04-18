/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:15:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/18 10:34:19 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				are_all_placed(t_minos *minos, t_map *map)
{
	size_t i;
	int j;
	int num;
	char *alphabet;
	char *mapstr;

	mapstr = map->mapstr;
	i = 0;
	j = 0;
	num = 0;
	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (i < ft_strlen(mapstr))
	{
		while (j < minos->num_mino)
		{
			if (mapstr[i] == alphabet[j])
				num++;
			j++;
		}
		j = 0;
		i++;
	}
	return (num == minos->num_mino);
}

int fillit_solve(t_minos *minos, t_map *map, size_t index, int next_mino)
{
    if (!map)
        map = createmap(ft_sqrt_cl(minos->num_mino * 4));
    if (index == (size_t)map->mapsize * MINO_STR_LEN - 1 && index != 0)
    {
        if (are_all_placed(minos, map))
        {
            ft_putendl(map->mapstr);
            return (1);
        }
        map = new_map_plus_one(map);
        fillit_solve(minos, map, 0, 0);
    }
    if (!check_place_mino(minos->minolist[next_mino % minos->num_mino - 1], map, index, next_mino))
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
        if (place_mino(minos->minolist[next_mino % minos->num_mino - 1], map, index, next_mino))
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
            unplace_mino(map, next_mino % (minos->num_mino - 1));
        }
    }
    return (0);
}
