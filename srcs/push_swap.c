/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:43:21 by syamada           #+#    #+#             */
/*   Updated: 2018/08/28 14:57:00 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		oplist_printer(t_oplist *oplist)
{
	oplist = rev_oplist(oplist);
	while (oplist)
	{
		print_oplist(oplist);
		oplist = oplist->next;
	}
	oplistdel(&oplist);
}

int				main(int argc, char **argv)
{
	t_stack		*stack;
	char		option;
	t_oplist	*oplist;
	t_algos		*f;

	stack = NULL;
	oplist = NULL;
	if (argc < 2)
		return (0);
	argv = check_option(&argc, argv, &option);
	if (((option & (LV | LC)) && argc == 1) || argc == 2)
	{
		if (!(argv = ft_strsplit(argv[argc - 1], ' ')))
			error_exit(option);
	}
	else
		argv += (option & (LV | LC)) ? 0 : 1;
	if (!create_stack(&stack, argv, option))
		error_exit(option);
	//f = set_algos();
	//oplist = pick_sort_algo(stack, copy_stack(stack), f);
	oplist = sort_with_optimize(stack);
	free(f);
	oplist_printer(oplist);
	return (0);
}
