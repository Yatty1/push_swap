/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 21:01:08 by syamada           #+#    #+#             */
/*   Updated: 2018/08/25 21:44:58 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int		partition(int **input, int left, int right)
{
	int		*arr;
	int		pivot;
	int		j;
	int		i;

	i = left;
	j = left;
	pivot = right;
	arr = *input;
	while (j < pivot)
	{
		if (arr[j] < arr[pivot])
			swap(&arr[i++], &arr[j]);
		j++;
	}
	swap(&arr[i], &arr[right]);
	return (i);
}

void			quick_sort(int **input, int left, int right)
{
	int		pivot;

	if (left >= right)
		return ;
	pivot = partition(input, left, right);
	quick_sort(input, left, pivot - 1);
	quick_sort(input, pivot + 1, right);
}

int				*sort_stack_with_quick(t_stack *stack)
{
	int		len;
	int		i;
	int		*arr;

	i = 0;
	len = stack_len(stack);
	arr = (int *)malloc(sizeof(int) * len);
	while (stack)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
	quick_sort(&arr, 0, len - 1);
	return (arr);
}
