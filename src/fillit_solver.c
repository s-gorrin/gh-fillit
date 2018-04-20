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

void fillit_solver(char **minos_list)
{
    t_map *map;
    t_mino **minos;
    
    map = createmap(0);
    map->num_mino = ft_arrlen(minos_list);
    minos = get_mino_array(mino_list, map->num_mino);
    map = createmap(ft_sqrt_cl(map->num_mino * 4));
    while (check_map(map, minos, 0, map->num_mino) == 0)
        map = next_map_plus_one(map);
    ft_putendl(map->mapstr);
}

int check_map(t_map *map, t_minos **minos, int index, int num_mino)
{
    int next_mino = 0;

    if (num_mino == 0)
        return (1);
    if (index == MAP_AREA - 3)
        return (0);
    while (next_mino < map->num_mino)
    {
        while (minos[next_mino]->location == -1)
        {
            if (place_mino(minos->minolist[next_mino], map, index))
                check_map(map, minos, index + 1, num_mino - 1);
            next_mino++;
        }
        while (minos[next_mino]->location != -1)
            next_mino--;
        index = unplace_mino(minos[next_mino], map);
        check_map(map, minos, index, num_mino + 1)
    }
    return(0);
}