/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:04:49 by syamada           #+#    #+#             */
/*   Updated: 2018/08/09 17:18:30 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_status(t_stack *a, t_stack *b, char *inst)
{
	ft_putendl(inst);
	ft_putstr("A[ ");
	while (a)
	{
		ft_printf("%d ", a->data);
		a = a->next;
	}
	ft_putstr("]\n");
	ft_putstr("B[ ");
	while (b)
	{
		ft_printf("%d ", b->data);
		b = b->next;
	}
	ft_putstr("]\n");
}
