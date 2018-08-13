/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:08:49 by syamada           #+#    #+#             */
/*   Updated: 2018/08/12 13:26:54 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strequ("sa", str) || ft_strequ("sb", str)
			|| ft_strequ("ss", str) || ft_strequ("pa", str)
			|| ft_strequ("pb", str) || ft_strequ("ra", str)
			|| ft_strequ("rb", str) || ft_strequ("rr", str)
			|| ft_strequ("rra", str) || ft_strequ("rrb", str)
			|| ft_strequ("rrr", str))
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

void	free_input(char **input)
{
	int		i;

	i = 0;
	while (input[i])
		ft_strdel(&input[i++]);
	free(input);
}
