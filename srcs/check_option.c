/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:40:44 by syamada           #+#    #+#             */
/*   Updated: 2018/08/25 19:21:30 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_option(int *argc, char **argv, char *option)
{
	int		i;

	i = 1;
	if (*argc < 2)
		return (argv);
	if (ft_strequ("-v", argv[i]))
		*option |= LV;
	else if (ft_strequ("-c", argv[i]))
		*option |= LC;
	else if (ft_strequ("-cv", argv[i]) || ft_strequ("-vc", argv[i]))
	{
		*option |= LC;
		*option |= LV;
	}
	if (*option & (LV | LC))
	{
		argv += 2;
		*argc -= 2;
	}
	return (argv);
}
