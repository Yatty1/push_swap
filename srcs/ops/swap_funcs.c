/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:29:01 by syamada           #+#    #+#             */
/*   Updated: 2018/08/10 13:31:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_a(t_stack **a, t_stack **b)
{
	int		tmp;

	if (!a || !b || !*a)
		return ;
	if (!(*a)->next)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
}

void		swap_b(t_stack **a, t_stack **b)
{
	int		tmp;

	if (!a || !b || !*b)
		return ;
	if (!(*b)->next)
		return ;
	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
}

void		swap_ab(t_stack **a, t_stack **b)
{
	swap_a(a, b);
	swap_b(a, b);
}
