/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:41:49 by sgorrin           #+#    #+#             */
/*   Updated: 2018/04/12 14:41:52 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @Function: writes "error" to error out
** @Return: returns 0 so that it can be called in a return statement
*/

int	ft_error(void)
{
	write(2, "error\n", 6);
	return (0);
}
