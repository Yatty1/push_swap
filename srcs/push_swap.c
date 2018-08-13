/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:43:21 by syamada           #+#    #+#             */
/*   Updated: 2018/08/12 21:29:21 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*stack;
	t_option	option;
	t_oplist	*oplist;
	t_stack		*copy;
	algos		*f;

	stack = NULL;
	oplist = NULL;
	argv = check_option(argc, argv, &option);
	if (!create_stack(&stack, argv, option))
		error_exit(option);
	copy = copy_stack(stack);
	if (!(f = set_algos()))
		error_exit(option);
	oplist = pick_sort_algo(stack, copy, f);
	free(f);
	ft_stackdel(&copy);
	oplist = rev_oplist(oplist);
	print_oplist(oplist);
	oplistdel(&oplist);
	while (1);
	return (0);
}
