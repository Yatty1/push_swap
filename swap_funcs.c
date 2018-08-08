/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:29:01 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 16:52:27 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_a(t_stack **a, t_stack **b)
{
	int		tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
}

void		swap_b(t_stack **a, t_stack **b)
{
	int		tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
}

void		swap_ab(t_stack **a, t_stack **b)
{
	int		tmp;

	if (a == NULL || b == NULL)
		return ;
	swap_a(a, b);
	swap_b(a, b);
}
