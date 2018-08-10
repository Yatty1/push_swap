/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:38:14 by syamada           #+#    #+#             */
/*   Updated: 2018/08/10 13:31:17 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_addstack(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*st;

	new = ft_stacknew(num);
	if (stack == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	st = *stack;
	while (st->next)
		st = st->next;
	st->next = new;
}

int			ft_searchstack(t_stack *stack, int target)
{
	while (stack)
	{
		if (stack->data == target)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void		print_stack(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		ft_printf("stack%d: num: %d\n", i, stack->data);
		stack = stack->next;
		i++;
	}
}
