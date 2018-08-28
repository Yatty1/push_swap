/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:02:48 by syamada           #+#    #+#             */
/*   Updated: 2018/08/28 16:16:49 by syamada          ###   ########.fr       */
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

int			get_max(t_stack *stack)
{
	int		max;

	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

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
