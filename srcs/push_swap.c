/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:43:21 by syamada           #+#    #+#             */
/*   Updated: 2018/09/13 22:09:58 by syamada          ###   ########.fr       */
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
	char		**av;
	t_oplist	*oplist;

	stack = NULL;
	oplist = NULL;
	av = NULL;
	if (argc < 2)
		return (0);
	argv = check_option(&argc, argv, &option);
	if (((option & (LV | LC | LT)) && argc == 1) || argc == 2)
		av = ft_strsplit(argv[argc - 1], ' ');
	else
		argv += (option & (LV | LC | LT)) ? 0 : 1;
	if (!create_stack(&stack, av ? av : argv, option))
		error_exit(&av, option);
	oplist = pick_algo(stack);
	oplist_printer(oplist);
	free_input(&av);
	return (0);
}
