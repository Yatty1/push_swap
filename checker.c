/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:10:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 20:54:18 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strequ("sa", str) || ft_strequ("sb", str) || ft_strequ("ss", str)
			|| ft_strequ("pa", str) || ft_strequ("pb", str) || ft_strequ("ra", str)
			|| ft_strequ("rb", str) || ft_strequ("rr", str) || ft_strequ("rra", str)
			|| ft_strequ("rrb", str) || ft_strequ("rrr", str))
		return (1);
	return (0);
}

char	**read_instruction(void)
{
	char	*str;
	char	*input;
	char	**two_d;

	str = NULL;
	input = ft_strnew(1);
	while (get_next_line(0, &str) > 0)
	{
		if (is_valid(str))
			input = ft_strjoinfree_with(input, str, ',');
		else
		{
			ft_strdel(&str);
			ft_strdel(&input);
			return (NULL);
		}
	}
	if (!(two_d = ft_strsplit(input, ',')) || !*input)
	{
		ft_strdel(&input);
		return (NULL);
	}
	ft_strdel(&input);
	return (two_d);
}

void	dispatcher(t_stack **a, t_stack **b, char *input)
{
	ft_putendl(input);
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
}

void	check(char **input, t_stack *a)
{
	int		i;
	t_stack *b;

	i = 0;
	b = NULL;
	while (input[i])
		dispatcher(&a, &b, input[i++]);
	while (a->next)
	{
		if (a->data > a->next->data)
		{
			ft_putstrerr("KO\n");
			ft_stackdel(&a);
			ft_stackdel(&b);
			ft_strdel(input);//might leak since it's two dimensional
			exit(-1);
		}
		a = a->next;
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
	{
		ft_putstrerr("Error\n");
		return (0);
	}
	check(input, stack);
	ft_putstr("OK\n");
	ft_strdel(input);
	return (0);
}
