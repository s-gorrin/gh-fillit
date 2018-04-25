/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:03:00 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/24 14:48:26 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	fillit_cleanup(t_map *map, t_mino **mino)
{
    int count;
    int i;

    count = map->num_mino;
    i = 0;
    while (i < count)
    {
        free(mino[i]);
        i++;
    }
    free(mino);
	free(map->mapstr);
	free(map);
}
