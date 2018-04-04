/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:55:27 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/04 15:52:12 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Reference:
** i0 =    {5,10,15,0};
** i90 =   {1,2,3,0};
**
** o0 =    {1,5,6,0};
**
** t0 =    {1,2,6,0};
** t90 =   {4,5,10,0};
** t180 =  {4,5,6,0};
** t270 =  {5,6,10,0};
**
** s0 =    {1,4,5,0};
** s90 =   {5,6,11,0};
** z0 =    {1,6,7,0};
** z90 =   {4,5,9,0};
**
** j0 =    {5,9,10,0};
** j90 =   {5,6,7,0};
** j180 =  {1,5,10,0};
** j270 =  {1,2,7,0};
**
** l0 =    {5,10,11,0};
** l90 =   {1,2,5,0};
** l180 =  {1,6,11,0};
** l270 =  {3,4,5,0};
*/

char	*one_first(char *mstr, int i)
{
	if (mstr[i + 2] == '#')
	{
		if (mstr[i + 3] == '#')
			return ({1,2,3,0});
		if (mstr[i + 5] == '#')
			return ({1,2,5,0});
		if (mstr[i + 6] == '#')
			return ({1,2,5,0});
		if (mstr[i + 7] == '#')
			return ({1,2,7,0});
	}
	if (mstr[i + 4] == '#' && mstr[i + 5] == '#')
		return ({1,4,5,0});
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		return ({1,5,6,0});
	if (mstr[1 + 5] == '#' && mstr[i + 10] == '#')
		return ({1,5,10,0});
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		return ({1,6,7,0});
	if (mstr[1 + 6] == '#' && mstr[i + 11] == '#')
		return ({1,6,11,0});
	else
		return (NULL);
}

char	*four_first(char *mstr, int i)
{
	if (mstr[i + 5] == '#' && mstr[i + 6] == '#')
		return ({4,5,6,0});
	if (mstr[i + 5] == '#' && mstr[i + 9] == '#')
		return ({4,5,9,0});
	if (mstr[i + 5] == '#' && mstr[i + 10] == '#')
		return ({4,5,10,0});
	else
		return (NULL);
}

char	*five_first(char *mstr, int i)
{
	if (mstr[i + 6] == '#' && mstr[i + 7] == '#')
		return ({5,6,7,0});
	if (mstr[i + 6] == '#' && mstr[i + 10] == '#')
		return ({5,6,10,0});
	if (mstr[i + 6] == '#' && mstr[i + 11] == '#')
		return ({5,6,11,0});
	if (mstr[i + 9] == '#' && mstr[i + 10] == '#')
		return ({5,9,10,0});
	if (mstr[i + 10] == '#' && mstr[i + 11] == '#')
		return ({5,10,11,0});
	if (mstr[i + 10] == '#' && mstr[i + 15] == '#')
		return ({5,10,15,0});
	else
		return (NULL);
}

/*
** Each possible piece is hard coded in as offsets from first '#' that is found.
** They are pushed out to different functions to pass Norminette.
** Return is a char *str of numbers, or NULL for invalid piece/malloc fail.
*/

int	mino_id(char *minostr)
{
	int	i;
	char	*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(*ret) * 4)))
		return (NULL);
	while (minostr[i] != '#')
		i++;
	if (minostr[i + 1] == '#')
		ret = one_first(minostr, i);
	else if (minostr[i + 3] == '#')
		ret = {3,4,5,0};
	else if (minostr[i + 4] == '#')
		ret = four_first(minostr, i);
	else if (minostr[i + 5] == '#')
		ret = five_first(minostr, i);
	else
		return (NULL);
	return (ret);
}
