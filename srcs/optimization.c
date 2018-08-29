/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:29:13 by syamada           #+#    #+#             */
/*   Updated: 2018/08/28 18:17:19 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_steps(t_oplist *oplist)
{
	int		i;

	i = 0;
	while (oplist)
	{
		i++;
		oplist = oplist->next;
	}
	return (i);
}

t_algos		*set_algos(void)
{
	t_algos	*f;

	if (!(f = (t_algos *)malloc(sizeof(t_algos) * ALGO_NUM)))
		return (NULL);
	f[0] = &insertion_sort;
	f[1] = &bubble_sort;
	return (f);
}

t_stack		*copy_stack(t_stack *stack)
{
	t_stack		*new;

	new = NULL;
	while (stack)
	{
		ft_addstack(&new, stack->data);
		stack = stack->next;
	}
	return (new);
}

t_oplist	*pick_sort_algo(t_stack *stack, t_stack *org, t_algos *f)
{
	t_oplist	*oplist;
	t_oplist	*tmp_op;
	int			steps;
	int			tmp;
	int			i;

	i = 0;
	oplist = f[i++](stack);
	steps = count_steps(oplist);
	while (i < ALGO_NUM)
	{
		stack = copy_stack(org);
		tmp_op = f[i](stack);
		if ((tmp = count_steps(tmp_op)) < steps)
		{
			oplistdel(&oplist);
			steps = tmp;
			oplist = tmp_op;
		}
		else
			oplistdel(&tmp_op);
		i++;
	}
	ft_stackdel(&org);
	return (oplist);
}

t_oplist	*pick_algo(t_stack *stack)
{
	int			len;
	t_oplist	*op;

	op = NULL;
	len = stack_len(stack);
	if (len < 50)
		op = small_sort(stack);
	else
		op = divide_sort(stack);
	return (op);
}
