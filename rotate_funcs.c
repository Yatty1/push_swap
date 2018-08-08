/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:58:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 17:11:04 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_a(t_stack **a, t_stack **b)
{
	int		num;

	if (a == NULL || b == NULL)
		return ;
	if (*a == NULL)
		return ;
	num = ft_pop(a);
	ft_addstack(a, num);
}

void		rotate_b(t_stack **a, t_stack **b)
{
	int		num;

	if (a == NULL || b == NULL)
		return ;
	if (*b == NULL)
		return ;
	num = ft_pop(b);
	ft_addstack(b, num);
}

void		rotate_ab(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL || *a == NULL || *b == NULL)
		return ;
	rotate_a(a, b);
	rotate_b(a, b);
}
