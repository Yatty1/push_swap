/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:19:37 by syamada           #+#    #+#             */
/*   Updated: 2018/08/25 20:02:25 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			set_max(t_object **object)
{
	int		max;
	t_stack	*stack;

	stack = (*object)->stack;
	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

t_oplist		*bubble_sort(t_stack *a)
{
	t_stack		*b;
	t_oplist	*oplist;
	int			max;

	b = NULL;
	oplist = NULL;
	max = get_max(a);
	while ((!is_ascending(a)))
	{
		if (a->data > a->next->data && max != a->data)
			swap_a(&a, &b, &oplist);
		if (is_ascending(a))
			break ;
		rotate_a(&a, &b, &oplist);
		if (is_ascending(a))
			break ;
	}
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (oplist);
}
