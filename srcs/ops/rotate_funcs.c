/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:58:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 20:43:30 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_a(t_stack **a, t_stack **b)
{
	int		num;

	if (!a || !b)
		return ;
	if (!*a || !(*a)->next)
		return ;
	num = ft_pop(a);
	ft_addstack(a, num);
}

void		rotate_b(t_stack **a, t_stack **b)
{
	int		num;

	if (!a || !b)
		return ;
	if (!*b || !(*b)->next)
		return ;
	num = ft_pop(b);
	ft_addstack(b, num);
}

void		rotate_ab(t_stack **a, t_stack **b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}
