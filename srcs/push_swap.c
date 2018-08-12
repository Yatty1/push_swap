/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:43:21 by syamada           #+#    #+#             */
/*   Updated: 2018/08/11 17:36:31 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*stack;
	t_option	option;
	t_oplist	*oplist;

	stack = NULL;
	oplist = NULL;
	stack = create_stack(stack, argv, option);
	oplist = insertion_sort(stack);
	oplist = rev_oplist(oplist);
	print_oplist(oplist);
	return (0);
}
