/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:03:57 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 14:42:55 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_minus(intmax_t *n)
{
	int		is_minus;

	is_minus = 0;
	if (*n < 0)
	{
		is_minus = 1;
		*n *= -1;
	}
	return (is_minus);
}

static int	get_len(intmax_t num, int is_minus)
{
	int	i;

	i = 2;
	while ((num /= 10) > 0)
		i++;
	i += is_minus;
	return (i);
}

char		*ft_imaxtoa(intmax_t n)
{
	char	*str;
	int		is_minus;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	is_minus = check_minus(&n);
	i = get_len(n, is_minus);
	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	if (is_minus)
		str[0] = '-';
	return (str);
}
