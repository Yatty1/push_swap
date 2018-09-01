/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:38:14 by syamada           #+#    #+#             */
/*   Updated: 2018/08/28 16:29:42 by syamada          ###   ########.fr       */
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

int		search_index(t_stack *stack, int target)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (stack->data == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}



int			stack_len(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void		stack_status(t_stack *a, t_stack *b, char *inst)
{
	ft_putendl(inst);
	ft_putstr("A[ ");
	while (a)
	{
		ft_printf("%d ", a->data);
		a = a->next;
	}
	ft_putstr("]\n");
	ft_putstr("B[ ");
	while (b)
	{
		ft_printf("%d ", b->data);
		b = b->next;
	}
	ft_putstr("]\n");
}
