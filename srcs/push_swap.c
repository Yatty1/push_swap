/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:43:21 by syamada           #+#    #+#             */
/*   Updated: 2018/08/12 18:03:22 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*stack;
	t_option	option;
	t_oplist	*oplist;
	t_stack		*copy;

	stack = NULL;
	oplist = NULL;
	argv = check_option(argc, argv, &option);
	if (!(stack = create_stack(stack, argv, option)))
		error_exit(option);
	copy = copy_stack(stack);
	oplist = pick_sort_algo(stack, copy, set_algos());
	ft_stackdel(&copy);
	oplist = rev_oplist(oplist);
	print_oplist(oplist);
	oplistdel(&oplist);
	while (1);
	return (0);
}
