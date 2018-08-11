/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:58:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/11 14:21:19 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_a(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		num;

	if (!a || !b)
		return ;
	if (!*a || !(*a)->next)
		return ;
	num = ft_pop(a);
	ft_addstack(a, num);
	add_oplist(oplist, RA);
}

void		rotate_b(t_stack **a, t_stack **b, t_oplist **oplist)
{
	int		num;

	if (!a || !b)
		return ;
	if (!*b || !(*b)->next)
		return ;
	num = ft_pop(b);
	ft_addstack(b, num);
	add_oplist(oplist, RB);
}

void		rotate_ab(t_stack **a, t_stack **b, t_oplist **oplist)
{
	rotate_a(a, b, NULL);
	rotate_b(a, b, NULL);
	add_oplist(oplist, RR);
}
