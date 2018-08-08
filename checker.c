/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:10:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 18:14:48 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

t_stack	*create_stack(t_stack *stack, char *str)
{
	int		i;
	long	num;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	num = ft_atol(str);
	if (str[i] != '\0' || num > 2147483647 || num < -2147483648
				|| ft_searchstack(stack, num))
	{
		if (stack != NULL)
			ft_stackdel(&stack);
		return (NULL);
	}
	ft_addstack(&stack, (int)num);
	return (stack);
}

int		is_valid(char *str)
{
	if (ft_strequ("sa", str) || ft_strequ("sb", str) || ft_strequ("ss", str)
			|| ft_strequ("pa", str) || ft_strequ("pb", str) || ft_strequ("ra", str)
			|| ft_strequ("rb", str) || ft_strequ("rr", str) || ft_strequ("rra", str)
			|| ft_strequ("rrb", str) || ft_strequ("rrr", str))
		return (1);
	return (0);
}

char	**read_stdin(void)
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
	if (!input || !*input)
		return (NULL);
	if (!(two_d = ft_strsplit(input, ',')))
		return (NULL);
	ft_strdel(&input);
	return (two_d);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**input;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	input = NULL;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (!(stack = create_stack(stack, argv[i])))
		{
			ft_putstrerr("Error\n");
			return (0);
		}
		i++;
	}
	print_stack(stack);
	input = read_stdin();
	int j = 0;
	while (input[j])
		ft_putendl(input[j++]);
	ft_strdel(input);
	while (1);
	return (0);
}
