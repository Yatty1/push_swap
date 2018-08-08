/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:03:32 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 17:10:03 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rev_rotate_a(t_stack **a, t_stack **b)
{
	int		num;
	t_stack	*stack;

	if (a == NULL || b == NULL || *a == NULL)
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

	if (a == NULL || b == NULL || *b == NULL)
		return ;
	stack = *b;
	while (stack->next)
		stack = stack->next;
	num = stack->data;
	ft_stackpush(b, num);
}

void		rev_rotate_ab(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL || *a == NULL || *b == NULL)
		return ;
	rev_rotate_a(a, b);
	rev_rotate_b(a, b);
}
