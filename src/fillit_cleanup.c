/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:03:00 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/26 15:04:12 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_cleanup(t_map *map, t_mino **mino)
{
	int i;

	i = 0;
	while (i < map->num_mino)
	{
		ft_strdel(&(mino[i]->minostr));
		free(mino[i]);
		i++;
	}
	free(mino);
	free(map->mapstr);
	free(map);
}
