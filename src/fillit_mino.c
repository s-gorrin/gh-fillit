/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_mino.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:59:30 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/20 23:04:58 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mino	*createmino(char *minosstr, int index)
{
	t_mino	*mino;

	mino = (t_mino *)ft_memalloc(sizeof(t_mino));
	mino->minostr = minosstr;
	mino->location = -1;
	mino->letter = index + 'A';
	return (mino);
}
