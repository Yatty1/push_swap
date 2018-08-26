/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:03:32 by syamada           #+#    #+#             */
/*   Updated: 2018/08/25 17:02:46 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rev_rotate_a(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		num;
	t_stack	*stack;
	t_stack	*pre;

	if (!a || !b || !*a)
		return ;
	if (!(*a)->next)
		return ;
	stack = *a;
	while (stack->next)
	{
		pre = stack;
		stack = stack->next;
	}
	num = stack->data;
	free(stack);
	pre->next = NULL;
	ft_stackpush(a, num);
	add_oplist(oplist, RRA);
}

void		rev_rotate_b(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		num;
	t_stack	*stack;
	t_stack *pre;

	if (!a || !b || !*b)
		return ;
	if (!(*b)->next)
		return ;
	stack = *b;
	while (stack->next)
	{
		pre = stack;
		stack = stack->next;
	}
	num = stack->data;
	free(stack);
	pre->next = NULL;
	ft_stackpush(b, num);
	add_oplist(oplist, RRB);
}

void		rev_rotate_ab(t_stack **a, t_stack **b, t_oplist **oplist)
{
	rev_rotate_a(a, b, NULL);
	rev_rotate_b(a, b, NULL);
	add_oplist(oplist, RRR);
}
