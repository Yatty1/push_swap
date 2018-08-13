/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:40:44 by syamada           #+#    #+#             */
/*   Updated: 2018/08/12 14:34:34 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_option(int argc, char **argv, t_option *option)
{
	int		i;

	i = 1;
	option->v = 0;
	option->c = 0;
	if (argc < 2)
		return (argv);
	if (ft_strequ("-v", argv[i]))
		option->v = 1;
	else if (ft_strequ("-c", argv[i]))
		option->c = 1;
	else if (ft_strequ("-cv", argv[i]) || ft_strequ("-vc", argv[i]))
	{
		option->c = 1;
		option->v = 1;
	}
	if (option->v || option->c)
		argv += 1;
	return (argv);
}
