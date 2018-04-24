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

void	fillit_cleanup(t_map *map, t_mino **mino)
{
	t_mino *current;
	t_mino *tmp;
	int count;

	count = map->num_mino;
	current = *mino;
	tmp = NULL;
	while (count)
	{
		tmp = current;
		current++;
		free(tmp);
		count--;
	}

	free(map->mapstr);
	free(map);
}
