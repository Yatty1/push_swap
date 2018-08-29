/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorexit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:20:01 by syamada           #+#    #+#             */
/*   Updated: 2018/08/28 19:50:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char option)
{
	if (option & LC)
		ft_putstrerr("\033[1;31mError\n");
	else
		ft_putstrerr("\033[0;37mError\n");
	exit(-1);
}

void	free_exit(char *str, char *input, char option)
{
	ft_strdel(&str);
	ft_strdel(&input);
	if (option & LC)
		ft_putstrerr("\033[1;31mError\n");
	else
		ft_putstrerr("\033[0;37mError\n");
	exit(-1);
}
