/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:14:16 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 22:18:47 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	map_line_len(char const *map)
{
	int	line_len;

	line_len = 0;
	while (map[line_len] != '\n')
		line_len++;
	return (line_len);
}
