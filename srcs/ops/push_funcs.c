/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:52:51 by syamada           #+#    #+#             */
/*   Updated: 2018/08/25 14:24:44 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_a(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		num;

	if (!a || !b)
		return ;
	if (!*b)
		return ;
	num = ft_pop(b);
	ft_stackpush(a, num);
	add_oplist(oplist, PA);
}

void		push_b(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		num;

	if (!a || !b)
		return ;
	if (!*a)
		return ;
	num = ft_pop(a);
	ft_stackpush(b, num);
	add_oplist(oplist, PB);
}
