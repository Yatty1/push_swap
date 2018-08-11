/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:23:23 by syamada           #+#    #+#             */
/*   Updated: 2018/08/11 10:29:20 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_stacknew(int num)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->data = num;
	stack->next = NULL;
	return (stack);
}

void		ft_stackdel(t_stack **stack)
{
	t_stack	*st;
	t_stack	*n_st;

	if (!stack || !*stack)
		return ;
	st = *stack;
	while (st)
	{
		n_st = st->next;
		st->data = 0;
		free(st);
		st = n_st;
	}
	*stack = NULL;
}

int			ft_pop(t_stack **stack)
{
	int		pop;
	t_stack	*tmp;

	if (*stack == NULL)
		return (-1);
	pop = (*stack)->data;
	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
	tmp = NULL;
	return (pop);
}

void		ft_stackpush(t_stack **stack, int num)
{
	t_stack	*new;

	if (stack == NULL)
		return ;
	new = ft_stacknew(num);
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}
