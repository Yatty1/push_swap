/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oplist_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:52:10 by syamada           #+#    #+#             */
/*   Updated: 2018/08/12 18:01:49 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			oplist_len(t_oplist *oplist)
{
	int		i;

	i = 0;
	while (oplist)
	{
		oplist = oplist->next;
		i++;
	}
	return (i);
}

t_oplist	*rev_oplist(t_oplist *oplist)
{
	t_oplist	*list;
	t_op		tmp;
	int			len;
	int			i;

	if (!oplist)
		return (NULL);
	len = oplist_len(oplist);
	while (len)
	{
		i = 0;
		list = oplist;
		while (i < len - 1)
		{
			tmp = list->op;
			list->op = list->next->op;
			list->next->op = tmp;
			list = list->next;
			i++;
		}
		len--;
	}
	return (oplist);
}
