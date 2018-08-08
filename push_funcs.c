/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:52:51 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 16:58:11 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_a(t_stack **a, t_stack **b)
{
	int		num;

	if (a == NULL || b == NULL)
		return ;
	if (*b == NULL)
		return ;
	num = ft_pop(b);
	ft_stackpush(a, num);
}

void		push_b(t_stack **a, t_stack **b)
{
	int		num;

	if (a == NULL || b == NULL)
		return ;
	if (*a == NULL)
		return ;
	num = ft_pop(a);
	ft_stackpush(b, num);
}
