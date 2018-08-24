/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oplist_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:47:00 by syamada           #+#    #+#             */
/*   Updated: 2018/08/21 19:55:30 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oplist	*newoplist(t_op op)
{
	t_oplist	*oplist;

	oplist = (t_oplist *)malloc(sizeof(t_oplist));
	oplist->op = op;
	oplist->next = NULL;
	return (oplist);
}

void		add_oplist(t_oplist **oplist, t_op op)
{
	t_oplist	*new;

	if (!oplist)
		return ;
	if (!*oplist)
	{
		*oplist = newoplist(op);
		return ;
	}
	new = newoplist(op);
	new->next = *oplist;
	*oplist = new;
}

void		oplistdel(t_oplist **oplist)
{
	t_oplist	*op;
	t_oplist	*tmp;

	if (!oplist || !*oplist)
		return ;
	op = *oplist;
	while (op)
	{
		tmp = op->next;
		free(op);
		op = tmp;
	}
	*oplist = NULL;
}

void		print_oplist(t_oplist *oplist)
{
	if (oplist->op == SA)
		ft_putendl("sa");
	else if (oplist->op == SB)
		ft_putendl("sb");
	else if (oplist->op == SS)
		ft_putendl("ss");
	else if (oplist->op == PA)
		ft_putendl("pa");
	else if (oplist->op == PB)
		ft_putendl("pb");
	else if (oplist->op == RA)
		ft_putendl("ra");
	else if (oplist->op == RB)
		ft_putendl("rb");
	else if (oplist->op == RR)
		ft_putendl("rr");
	else if (oplist->op == RRA)
		ft_putendl("rra");
	else if (oplist->op == RRB)
		ft_putendl("rrb");
	else if (oplist->op == RRR)
		ft_putendl("rrr");
}
