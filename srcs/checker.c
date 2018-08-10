/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:10:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/09 21:48:26 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatcher(t_stack **a, t_stack **b, char *input)
{
	if (ft_strequ("sa", input))
		swap_a(a, b);
	else if (ft_strequ("sb", input))
		swap_b(a, b);
	else if (ft_strequ("ss", input))
		swap_ab(a, b);
	else if (ft_strequ("pa", input))
		push_a(a, b);
	else if (ft_strequ("pb", input))
		push_b(a, b);
	else if (ft_strequ("ra", input))
		rotate_a(a, b);
	else if (ft_strequ("rb", input))
		rotate_b(a, b);
	else if (ft_strequ("rr", input))
		rotate_ab(a, b);
	else if (ft_strequ("rra", input))
		rev_rotate_a(a, b);
	else if (ft_strequ("rrb", input))
		rev_rotate_b(a, b);
	else if (ft_strequ("rrr", input))
		rev_rotate_ab(a, b);
	stack_status(*a, *b, input);
}

void	check(char **input, t_stack *a)
{
	int		i;
	t_stack *b;
	t_stack	*sorted;

	i = 0;
	b = NULL;
	while (input[i])
		dispatcher(&a, &b, input[i++]);
	sorted = a;
	while (sorted->next)
	{
		if (sorted->data > sorted->next->data)
		{
			ft_putstrerr("KO\n");
			ft_stackdel(&a);
			ft_stackdel(&b);
			free_input(input);
			exit(-1);
		}
		sorted = sorted->next;
	}
}

int		main(int argc, char **argv)
{
	char	**input;
	t_stack	*stack;

	stack = NULL;
	input = NULL;
	if (argc == 1)
		return (0);
	stack = create_stack(stack, argv);
	if (!(input = read_instruction()))
		error_exit();
	check(input, stack);
	ft_putstr("OK\n");
	free_input(input);
	return (0);
}
