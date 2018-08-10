/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 19:36:26 by syamada           #+#    #+#             */
/*   Updated: 2018/08/10 13:18:00 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(t_stack *stack, char **str, t_option option)
{
	int		i;
	int		j;
	long	num;

	i = 1;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-')
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		num = ft_atol(str[i]);
		if (str[i][j] != '\0' || num > 2147483647 || num < -2147483648
					|| ft_searchstack(stack, num))
		{
			if (stack != NULL)
				ft_stackdel(&stack);
			return (NULL);
		}
		ft_addstack(&stack, (int)num);
		i++;
	}
	return (stack);
}