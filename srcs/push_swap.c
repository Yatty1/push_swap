/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:43:21 by syamada           #+#    #+#             */
/*   Updated: 2018/08/14 13:32:53 by syamada          ###   ########.fr       */
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
	t_algos		*f;

	stack = NULL;
	oplist = NULL;
	if (argc < 2)
		return (0);
	argv = check_option(argc, argv, &option);
	if (!(input = ft_strsplit(argv[1], ' ')))
		error_exit(option);
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
