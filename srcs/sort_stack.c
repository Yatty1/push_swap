/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 08:36:25 by syamada           #+#    #+#             */
/*   Updated: 2018/08/11 14:56:03 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ascending(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		is_descending(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	swap_if_possible(t_stack **a, t_stack **b, t_oplist **oplist, char c)
{
	t_stack		*tmp;

	tmp = c == 'a' ? *a : *b;
	if (!tmp || !tmp->next)
		return ;
	if (tmp->data > tmp->next->data && c == 'a')
		swap_a(a, b, oplist);
	if (tmp->data < tmp->next->data && c == 'b')
		swap_b(a, b, oplist);
}

t_oplist	*sort(t_stack *a)
{
	t_stack 	*b;
	t_oplist	*oplist;
	int			tmp;

	b = NULL;
	oplist = NULL;
	if (is_ascending(a))
		return (oplist);
	swap_if_possible(&a, &b, &oplist, 'a');
	push_b(&a, &b, &oplist);
	while ((!is_ascending(a) || !is_descending(b)) || (a->data < b->data))
	{
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
