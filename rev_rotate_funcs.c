/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:03:32 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 20:44:21 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rev_rotate_a(t_stack **a, t_stack **b)
{
	int		num;
	t_stack	*stack;

	if (!a || !b || !*a)
		return ;
	if (!(*a)->next)
		return ;
	stack = *a;
	while (stack->next)
		stack = stack->next;
	num = stack->data;
	ft_stackpush(a, num);
}

void		rev_rotate_b(t_stack **a, t_stack **b)
{
	int		num;
	t_stack	*stack;

	if (!a || !b || !*b)
		return ;
	if (!(*b)->next)
		return ;
	stack = *b;
	while (stack->next)
		stack = stack->next;
	num = stack->data;
	ft_stackpush(b, num);
}

void		rev_rotate_ab(t_stack **a, t_stack **b)
{
	rev_rotate_a(a, b);
	rev_rotate_b(a, b);
}
