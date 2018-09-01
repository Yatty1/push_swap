/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:10:22 by syamada           #+#    #+#             */
/*   Updated: 2018/09/01 11:30:22 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			dispatcher(t_stack **a, t_stack **b, char *input, char option)
{
	if (ft_strequ("sa", input))
		swap_a(a, b, NULL);
	else if (ft_strequ("sb", input))
		swap_b(a, b, NULL);
	else if (ft_strequ("ss", input))
		swap_ab(a, b, NULL);
	else if (ft_strequ("pa", input))
		push_a(a, b, NULL);
	else if (ft_strequ("pb", input))
		push_b(a, b, NULL);
	else if (ft_strequ("ra", input))
		rotate_a(a, b, NULL);
	else if (ft_strequ("rb", input))
		rotate_b(a, b, NULL);
	else if (ft_strequ("rr", input))
		rotate_ab(a, b, NULL);
	else if (ft_strequ("rra", input))
		rev_rotate_a(a, b, NULL);
	else if (ft_strequ("rrb", input))
		rev_rotate_b(a, b, NULL);
	else if (ft_strequ("rrr", input))
		rev_rotate_ab(a, b, NULL);
	if (option & LV)
		stack_status(*a, *b, input);
}

void			check(char **input, t_stack *a, char option)
{
	int		i;
	t_stack *b;
	t_stack	*sorted;

	i = 0;
	b = NULL;
	while (input && *input && input[i])
		dispatcher(&a, &b, input[i++], option);
	if (!a || !a->next)
		return ;
	sorted = a;
	while (sorted->next)
	{
		if (sorted->data > sorted->next->data)
		{
			ft_stackdel(&a);
			free_input(&input);
			option & LC ? ft_putstrerr("\033[1;33mKO\n")
				: ft_putstrerr("\033[0;37mKO\n");
			exit(-1);
		}
		sorted = sorted->next;
	}
	ft_stackdel(&a);
}

static int		count_steps(char **input)
{
	int		i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int				main(int argc, char **argv)
{
	char		**input;
	char		**av;
	char		option;
	t_stack		*stack;

	stack = NULL;
	av = NULL;
	input = NULL;
	if (argc < 2)
		return (0);
	argv = check_option(&argc, argv, &option);
	if (((option & (LV | LC)) && argc == 1) || argc == 2)
		av = ft_strsplit(argv[argc - 1], ' ');
	else
		argv += (option & (LV | LC)) ? 0 : 1;
	if (!create_stack(&stack, av ? av : argv, option))
		error_exit(&av, option);
	input = read_instruction(option, &av);
	check(input, stack, option);
	(option & LC) ? ft_putstr("\033[1;32mOK\n") : ft_putstr("OK\n");
	(option & LT) ? ft_printf("\033[m %d steps\n", count_steps(input)) : 0;
	free_input(&input);
	free_input(&av);
	return (0);
}
