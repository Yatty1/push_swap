/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:02:48 by syamada           #+#    #+#             */
/*   Updated: 2018/08/31 13:00:16 by syamada          ###   ########.fr       */
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

int		optimize_max_index(t_stack *stack, int *index)
{
	int		i;
	t_max	max;
	t_max	s_max;
	int		tmp;

	i = 0;
	max.index = i;
	max.value = stack->data;
	s_max.index = i;
	s_max.value = stack->data;
	while (stack)
	{
		if ((tmp = stack->data) > max.value)
		{
			s_max.index = max.index;
			s_max.value = max.value;
			max.value = tmp;
			max.index = i;
		}
		stack = stack->next;
		i++;
	}
	*index = s_max.index != 0 && ABS_MID(max.index, i) < ABS_MID(s_max.index, i) ? max.index : s_max.index;
	return (i);
}


//process up to two moves. max and second max
void	max_top(t_stack **a, t_stack **b, t_oplist **op)
{
	int			index;
	int			len;
	t_object	ob;

	len = optimize_max_index(*b, &index);
	ob.op = (index < len / 2) ? RB : RRB;
	ob.offset = ABS_MID(index, len);
	while (ob.offset--)
		ob.op == RB ? rotate_b(a, b, op) : rev_rotate_b(a, b, op);
}
