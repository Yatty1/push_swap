/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:40:44 by syamada           #+#    #+#             */
/*   Updated: 2018/09/09 16:36:00 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_validoption(char c)
{
	if (c == 'v' || c == 'c' || c == 't')
		return (1);
	return (0);
}

char		**check_option(int *argc, char **argv, char *option)
{
	int		i;

	i = 1;
	if (*argc < 2 || argv[1][0] != '-')
		return (argv);
	while (argv[1][i])
	{
		if (!is_validoption(argv[1][i]))
			error_exit(NULL, *option);
		i++;
	}
	*option |= ft_strchr(argv[1], 'v') ? LV : 0;
	*option |= ft_strchr(argv[1], 'c') ? LC : 0;
	*option |= ft_strchr(argv[1], 't') ? LT : 0;
	if (*option & (LV | LC | LT))
	{
		argv += 2;
		*argc -= 2;
	}
	return (argv);
}
