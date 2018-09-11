/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorexit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:20:01 by syamada           #+#    #+#             */
/*   Updated: 2018/09/11 13:40:13 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char ***av, char option)
{
	free_input(av);
	if (option & LC)
		ft_putstrerr("\033[1;31mError\n");
	else
		ft_putstrerr("\033[0;37mError\n");
	exit(-1);
}

void	free_exit(char *str, char *input, char ***av, char option)
{
	ft_strdel(&str);
	ft_strdel(&input);
	free_input(av);
	if (option & LC)
		ft_putstrerr("\033[1;31mError\n");
	else
		ft_putstrerr("\033[0;37mError\n");
	exit(-1);
}
