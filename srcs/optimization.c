/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:29:13 by syamada           #+#    #+#             */
/*   Updated: 2018/08/12 18:03:02 by syamada          ###   ########.fr       */
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

algos		*set_algos(void)
{
	algos	*f;

	f = (algos *)malloc(sizeof(algos) * ALGO_NUM);
	f[0] = &insertion_sort;
	f[1] = &bubble_sort;
	return (f);
}

void		free_algos(algos *f)
{
	int		i;

	i = 0;
	while (i < ALGO_NUM)
	{
		free(f[i]);
		f[i] = NULL;
		i++;
	}
}

t_stack	*copy_stack(t_stack *stack)
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

t_oplist	*pick_sort_algo(t_stack *stack, t_stack *org, algos *f)
{
	t_oplist	*oplist;
	t_oplist	*tmp_op;
	int			steps;
	int			tmp;
	int			i;

	i = 0;
	oplist = f[i++](stack);
	steps = count_steps(oplist);
//	ft_printf("func %d: %dsetps\n", i, steps);
	ft_stackdel(&stack);
	while (i < ALGO_NUM)
	{
		stack = copy_stack(org);
		tmp_op = f[i](stack);
		ft_stackdel(&stack);
//		ft_printf("func %d: %dsetps\n", i + 1, count_steps(tmp_op));
		if ((tmp = count_steps(tmp_op)) < steps)
		{
			oplistdel(&oplist);
			steps = tmp;
			oplist = tmp_op;
		}
		i++;
	}
//	ft_printf("%dsteps picked\n", steps);
	//free_algos(f);
	return (oplist);
}
