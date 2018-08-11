/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:29:01 by syamada           #+#    #+#             */
/*   Updated: 2018/08/11 11:57:17 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_a(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		tmp;

	if (!a || !b || !*a)
		return ;
	if (!(*a)->next)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	add_oplist(oplist, SA);
}

void		swap_b(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		tmp;

	if (!a || !b || !*b)
		return ;
	if (!(*b)->next)
		return ;
	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
	add_oplist(oplist, SB);
}

void		swap_ab(t_stack **a, t_stack **b, t_oplist **oplist)
{
	swap_a(a, b, NULL);
	swap_b(a, b, NULL);
	add_oplist(oplist, SS);
}
