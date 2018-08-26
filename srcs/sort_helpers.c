/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:02:48 by syamada           #+#    #+#             */
/*   Updated: 2018/08/25 19:06:52 by syamada          ###   ########.fr       */
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
