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

void fillit_solver(t_minos **minos)
{
    t_map *map;
    
    map = createmap(0);
    map->num_mino = len(minos);
    map = createmap(map->num_mino);

    while (check_map(map, minos, 0, 0) == 0)
        map = next_map_plus_one(map);
    ft_putendl(map->mapstr);
}

int check_map(t_map *map, t_minos **minos, int index, int next_mino)
{
    if (index == MAP_AREA)
    {
        if (are_all_placed(map, minos, startmino))
            return (1);
        map = clearmap(map);
        check_map(map, minos, 0, startmino++);
    }
    if (can_place_any_mino(map, minos, index, startmino))
    {
        if (index % map->mapsize == 0)
            check_map(map, minos, index + 2);
        else
            check_map(map, minos, index + 1);
    }
    while (i < minos->num_mino)
    {
        place_piece(minos->minolist[i], map, index, i);
        check_map(map, minos, index);
        i++;
    }
}

int can_place_any_mino(t_map *map, t_mino *minos, int index)
{
    int num_mino;
    char *mino;
    int i;

    num_mino = minos->num_mino;
    i = 0;
    while (num_mion--)
        if (place_mino(minos->minolist[i++], map, index, i))
            return (1);
    return (0);
}