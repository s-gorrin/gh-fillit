/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgorrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 01:45:49 by sgorrin           #+#    #+#             */
/*   Updated: 2018/03/09 10:47:43 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *crr;
	t_list *nxt;

	crr = *alst;
	while (crr)
	{
		nxt = crr->next;
		del(crr->content, crr->content_size);
		free(crr);
		crr = nxt;
	}
	*alst = NULL;
}
