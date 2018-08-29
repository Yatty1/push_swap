/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:14:34 by syamada           #+#    #+#             */
/*   Updated: 2018/08/28 18:25:09 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			min_index(t_stack *stack, int *index)
{
	int		i;
	int		min;
	int		tmp;

	i = 0;
	min = stack->data;
	*index = 0;
	while (stack)
	{
		if ((tmp = stack->data) < min)
		{
			min = tmp;
			*index = i;
		}
		stack = stack->next;
		i++;
	}
	return (i);
}

void		min_top(t_stack **a, t_stack **b, t_oplist **op)
{
	int		index;
	int		len;

	len = min_index(*a, &index);
	if (index > len / 2)
	{
		len -= index;
		while (len--)
			rev_rotate_a(a, b, op);
	}
	else
	{
		while (index--)
			rotate_a(a, b, op);
	}
}

t_oplist	*small_sort(t_stack *a)
{
	t_oplist	*op;
	t_stack		*b;

	op = NULL;
	b = NULL;
	if (a && a->next)
		swap_a(&a, &b, &op);
	while (!is_ascending(a) || !is_descending(b) || (a->data < b->data))
	{
		min_top(&a, &b, &op);
		if (is_ascending(a))
			break;
		push_b(&a, &b, &op);
		if (is_ascending(a))
			break ;
	}
	while (b)
		push_a(&a, &b, &op);
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (op);
}
