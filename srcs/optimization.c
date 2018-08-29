/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:29:13 by syamada           #+#    #+#             */
/*   Updated: 2018/08/28 18:19:50 by syamada          ###   ########.fr       */
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

t_oplist	*pick_algo(t_stack *stack)
{
	int			len;
	t_oplist	*op;

	op = NULL;
	len = stack_len(stack);
	if (is_ascending(stack))
		return (op);
	if (len < 50)
		op = small_sort(stack);
	else
		op = divide_sort(stack);
	return (op);
}
