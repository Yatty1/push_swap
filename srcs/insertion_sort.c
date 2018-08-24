/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:19:24 by syamada           #+#    #+#             */
/*   Updated: 2018/08/19 14:15:44 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		preprocess(t_stack **a, t_stack **b, t_oplist **oplist)
{
	if (is_ascending(*a))
		return (0);
	swap_if_possible(a, b, oplist, 'a');
	if (is_ascending(*a))
		return (0);
	push_b(a, b, oplist);
	return (1);
}

static int		mainprocess(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		tmp;

	tmp = (*a)->data;
	rotate_a(a, b, oplist);
	while (*b && tmp < (*b)->data)
		push_a(a, b, oplist);
	rev_rotate_a(a, b, oplist);
	if (is_ascending(*a) && !*b)
		return (0);
	push_b(a, b, oplist);
	swap_if_possible(a, b, oplist, 'a');
	return (1);
}

t_oplist		*insertion_sort(t_stack *a)
{
	t_stack		*b;
	t_oplist	*oplist;
	int			tmp;

	b = NULL;
	oplist = NULL;
	if (!preprocess(&a, &b, &oplist))
		return (oplist);
	while ((!is_ascending(a) || !is_descending(b)) || (a->data < b->data))
	{
		if (a->data > b->data)
			push_b(&a, &b, &oplist);
		else if (a->data < b->data)
		{
			if (!mainprocess(&a, &b, &oplist))
				break ;
		}
		if (is_ascending(a) && !b)
			break ;
	}
	while (!is_stackempty(b))
		push_a(&a, &b, &oplist);
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (oplist);
}
