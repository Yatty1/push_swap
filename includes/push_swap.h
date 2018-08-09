/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:47:54 by syamada           #+#    #+#             */
/*   Updated: 2018/08/09 16:26:48 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

void			swap_a(t_stack **a, t_stack **b);
void			swap_b(t_stack **a, t_stack **b);
void			swap_ab(t_stack **a, t_stack **b);
void			push_a(t_stack **a, t_stack **b);
void			push_b(t_stack **a, t_stack **b);
void			rotate_a(t_stack **a, t_stack **b);
void			rotate_b(t_stack **a, t_stack **b);
void			rotate_ab(t_stack **a, t_stack **b);
void			rev_rotate_a(t_stack **a, t_stack **b);
void			rev_rotate_b(t_stack **a, t_stack **b);
void			rev_rotate_ab(t_stack **a, t_stack **b);

t_stack			*ft_stacknew(int num);
int				ft_pop(t_stack **stack);
void			ft_stackpush(t_stack **stack, int num);
void			ft_stackdel(t_stack **stack);
void			ft_addstack(t_stack **stack, int num);
int				ft_searchstack(t_stack *stack, int target);
void			print_stack(t_stack *stack);

t_stack			*create_stack(t_stack *stack, char **str);
void			error_exit(void);

char			**read_instruction(void);
int				is_valid(char *str);
void			free_input(char **input);

#endif
