/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorexit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:20:01 by syamada           #+#    #+#             */
/*   Updated: 2018/08/10 13:41:21 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_option option)
{
	if (option.c)
		ft_putstrerr("\033[1;31mError\n");
	else
		ft_putstrerr("Error\n");
	exit(-1);
}
