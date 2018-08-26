/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:17:30 by syamada           #+#    #+#             */
/*   Updated: 2018/08/25 21:48:25 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			max_index(t_stack *stack, int *index)
{
	int		i;
	int		max;
	int		tmp;

	i = 0;
	*index = i;
	max = stack->data;
	while (stack)
	{
		if ((tmp = stack->data) > max)
		{
			max = tmp;
			*index = i;
		}
		stack = stack->next;
		i++;
	}
	return (i);
}

void		max_top(t_stack **a, t_stack **b, t_oplist **op)
{
	int		index;
	int		len;

	len = max_index(*b, &index);
	if (index > len / 2)
	{
		len -= index;
		while (len--)
			rev_rotate_b(a, b, op);
	}
	else
	{
		while (index--)
			rotate_b(a, b, op);
	}
}

t_oplist	*simple_sort(t_stack *a)
{
	t_stack		*b;
	t_oplist	*op;
	int			len;

	b = NULL;
	op = NULL;
	len = stack_len(a);
	while (len--)
		push_b(&a, &b, &op);
	while (b)
	{
		max_top(&a, &b, &op);
		push_a(&a, &b, &op);
	}
	return (op);
}
