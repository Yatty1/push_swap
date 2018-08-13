/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:43:21 by syamada           #+#    #+#             */
/*   Updated: 2018/08/12 22:12:33 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		oplist_printer(t_oplist *oplist)
{
	while (oplist)
	{
		print_oplist(oplist);
		oplist = oplist->next;
	}
}

int				main(int argc, char **argv)
{
	t_stack		*stack;
	t_option	option;
	t_oplist	*oplist;
	char		**input;
	algos		*f;

	stack = NULL;
	oplist = NULL;
	if (argc < 2)
		return (0);
	if (!(input = ft_strsplit(argv[1], ' ')))
		error_exit(option);
	input = check_option(argc, input, &option);
	if (!create_stack(&stack, input, option))
		error_exit(option);
	if (!(f = set_algos()))
		error_exit(option);
	oplist = pick_sort_algo(stack, copy_stack(stack), f);
	free(f);
	oplist = rev_oplist(oplist);
	oplist_printer(oplist);
	oplistdel(&oplist);
	return (0);
}
