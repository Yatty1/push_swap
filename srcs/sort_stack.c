/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 08:36:25 by syamada           #+#    #+#             */
/*   Updated: 2018/08/11 17:36:30 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oplist	*quick_sort(t_stack *a)
{
	t_oplist	*oplist;

	oplist = NULL;
	return (oplist);
}

t_oplist	*insertion_sort(t_stack *a)
{
	t_stack 	*b;
	t_oplist	*oplist;
	int			tmp;

	b = NULL;
	oplist = NULL;
	if (is_ascending(a))
		return (oplist);
	swap_if_possible(&a, &b, &oplist, 'a');
	if (is_ascending(a))
		return (oplist);
	push_b(&a, &b, &oplist);
	while ((!is_ascending(a) || !is_descending(b)) || (a->data < b->data))
	{
		if (a->data > a->next->data)
			swap_a(&a, &b, &oplist);
		if (a->data > b->data)
			push_b(&a, &b, &oplist);
		else if (a->data < b->data)
		{
			tmp = a->data;
			rotate_a(&a, &b, &oplist);
			while (b && tmp < b->data)
				push_a(&a, &b, &oplist);
			rev_rotate_a(&a, &b, &oplist);
			push_b(&a, &b, &oplist);
		}
		if (is_ascending(a) && !b)
			break ;
	}
	while (!is_stackempty(b))
		push_a(&a, &b, &oplist);
	return (oplist);
}
