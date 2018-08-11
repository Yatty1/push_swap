/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:47:54 by syamada           #+#    #+#             */
/*   Updated: 2018/08/11 15:03:16 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef enum	e_op
{
	NO_OP,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_op;

typedef	struct	s_oplist
{
	t_op			op;
	struct s_oplist	*next;
}				t_oplist;

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

typedef	struct	s_option
{
	int		v;
	int		c;
}				t_option;

/*
** operation funcs
*/

void			swap_a(t_stack **a, t_stack **b, t_oplist **oplist);
void			swap_b(t_stack **a, t_stack **b, t_oplist **oplist);
void			swap_ab(t_stack **a, t_stack **b, t_oplist **oplist);
void			push_a(t_stack **a, t_stack **b, t_oplist **oplist);
void			push_b(t_stack **a, t_stack **b, t_oplist **oplist);
void			rotate_a(t_stack **a, t_stack **b, t_oplist **oplist);
void			rotate_b(t_stack **a, t_stack **b, t_oplist **oplist);
void			rotate_ab(t_stack **a, t_stack **b, t_oplist **oplist);
void			rev_rotate_a(t_stack **a, t_stack **b, t_oplist **oplist);
void			rev_rotate_b(t_stack **a, t_stack **b, t_oplist **oplist);
void			rev_rotate_ab(t_stack **a, t_stack **b, t_oplist **oplist);

/*
** stack funcs
*/

t_stack			*ft_stacknew(int num);
int				ft_pop(t_stack **stack);
void			ft_stackpush(t_stack **stack, int num);
void			ft_stackdel(t_stack **stack);
void			ft_addstack(t_stack **stack, int num);
int				ft_searchstack(t_stack *stack, int target);
void			print_stack(t_stack *stack);
void			stack_status(t_stack *a, t_stack *b, char *inst);
int				stack_len(t_stack *stack);
int				is_stackempty(t_stack *stack);

/*
** oplist funcs
*/

t_oplist		*newoplist(t_op op);
void			add_oplist(t_oplist **oplist, t_op op);
int				oplist_len(t_oplist *oplist);
t_oplist		*rev_oplist(t_oplist *oplist);
void			print_oplist(t_oplist *oplist);

/*
** shared funcs
*/

t_stack			*create_stack(t_stack *stack, char **str, t_option option);
void			error_exit(t_option option);

/*
** push_swap funcs
*/

int				is_ascending(t_stack *stack);
int				is_descending(t_stack *stack);
void			swap_if_possible(t_stack **a, t_stack **b,
									t_oplist **oplist, char c);
t_oplist		*sort(t_stack *a);

/*
** checker funcs
*/

char			**check_option(int argc, char **argv, t_option *option);
void			dispatcher(t_stack **a, t_stack **b, char *input, t_option option);
void			check(char **input, t_stack *a, t_option option);
char			**read_instruction(void);
int				is_valid(char *str);
void			free_input(char **input);

#endif
