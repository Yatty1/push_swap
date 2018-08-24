/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:10:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/20 21:16:36 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatcher(t_stack **a, t_stack **b, char *input, t_option option)
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
	if (option.v)
		stack_status(*a, *b, input);
}

void	check(char **input, t_stack *a, t_option option)
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
			ft_stackdel(&b);
			free_input(input);
			option.c ? ft_putstrerr("\033[1;33mKO\n")
				: ft_putstrerr("\033[0;37mKO\n");
			exit(-1);
		}
		sorted = sorted->next;
	}
}

int		main(int argc, char **argv)
{
	char		**input;
	t_stack		*stack;
	t_option	option;

	stack = NULL;
	input = NULL;
	if (argc < 2)
		return (0);
	argv = check_option(&argc, argv, &option);
	if (((option.v || option.c) && argc == 1) || argc == 2)
	{
		if (!(argv = ft_strsplit(argv[argc - 1], ' ')))
			error_exit(option);
	}
	else
		argv += (option.c || option.v) ? 0 : 1;
	if (!create_stack(&stack, argv, option))
		error_exit(option);
	input = read_instruction();
	check(input, stack, option);
	option.c ? ft_putstr("\033[1;32mOK\n") : ft_putstr("OK\n");
	free_input(input);
	return (0);
}
