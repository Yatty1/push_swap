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

int		optimize_max_index(t_stack *stack, t_maxob *mob)
{
	int		i;
	int		tmp;

	i = 0;
	mob->max.i = i;
	mob->max.value = stack->data;
	mob->s_max.i = i;
	mob->s_max.value = stack->data;
	while (stack)
	{
		if ((tmp = stack->data) > mob->max.value)
		{
			mob->s_max.i = mob->max.i;
			mob->s_max.value = mob->max.value;
			mob->max.value = tmp;
			mob->max.i = i;
		}
		stack = stack->next;
		i++;
	}
	mob->index = mob->s_max.i != 0 &&
		ABS_MID(mob->max.i, i) < ABS_MID(mob->s_max.i, i) ?
		mob->max.i : mob->s_max.i;
	mob->sec_i = mob->index == mob->max.i ? -1 : mob->max.i;
	return (i);
}

//process up to two moves. max and second max
void	max_top(t_stack **a, t_stack **b, t_oplist **op)
{
	t_maxob		mob;
	t_object	ob;

	ob.len = optimize_max_index(*b, &mob);
	ob.op = (mob.index < ob.len / 2) ? RB : RRB;
	ob.offset = ABS_MID(mob.index, ob.len);
	while (ob.offset--)
		ob.op == RB ? rotate_b(a, b, op) : rev_rotate_b(a, b, op);
	push_a(a, b, op);
	if (mob.sec_i < 0)
		return ;
	ob.op = (mob.sec_i < ob.len / 2) ? RB : RRB;
	ob.offset = ABS_MID(mob.sec_i, ob.len);
	while (ob.offset--)
		ob.op == RB ? rotate_b(a, b, op) : rev_rotate_b(a, b, op);
	push_a(a, b, op);
}
