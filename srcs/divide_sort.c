/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:21:38 by syamada           #+#    #+#             */
/*   Updated: 2018/08/31 13:00:17 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_object	*closest_target(t_stack *stack, t_object *ob)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (stack)
	{
		if (stack->data <= ob->target)
		{
			if ((tmp = ABS_MID(i, ob->len)) < ob->offset)
			{
				ob->offset = tmp;
				ob->op = i < ob->len / 2 ? RA : RRA;
			}
		}
		stack = stack->next;
		i++;
	}
	return (ob);
}

void		get_target(t_stack **a, t_stack **b, t_oplist **op, t_object *ob)
{
	ob = closest_target(*a, ob);
	while (ob->offset--)
		ob->op == RA ? rotate_a(a, b, op) : rev_rotate_a(a, b, op);
	ob->offset = ob->len;
}

void		rough_sort_push(t_stack **a, t_stack **b, t_oplist **op,
							t_object *ob)
{
	int		i;

	ob->target = ob->arr[ob->i_target];
	i = ob->inc;
	while (i--)
	{
		get_target(a, b, op, ob);
		push_b(a, b, op);
	}
}

void		init_object(t_object **ob, t_stack *a)
{
	*ob = (t_object *)malloc(sizeof(t_object));
	(*ob)->arr = sort_stack_with_quick(a, ob);
	(*ob)->inc = (*ob)->len < 250 ? (*ob)->len / 5 : (*ob)->len / 15;
	(*ob)->i_target = (*ob)->inc - 1;
	(*ob)->target = (*ob)->arr[(*ob)->i_target];
	(*ob)->sec_target = (*ob)->arr[(*ob)->i_target + (*ob)->inc];
	(*ob)->offset = (*ob)->len;
	(*ob)->op = RA;
}

t_oplist	*divide_sort(t_stack *a)
{
	t_object	*ob;
	t_oplist	*op;
	t_stack		*b;

	b = NULL;
	op = NULL;
	init_object(&ob, a);
	while (ob->i_target < ob->len)
	{
		rough_sort_push(&a, &b, &op, ob);
		ob->i_target += ob->inc;
	}
	while (a)
		push_b(&a, &b, &op);
	while (b)
	{
		max_top(&a, &b, &op);
		push_a(&a, &b, &op);
//		if (a && b)
//			printf("a: %d, b: %d\n", a->data, b->data);
		if (a && a->next && (a->data > a->next->data))
			swap_a(&a, &b, &op);
	}
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (op);
}
