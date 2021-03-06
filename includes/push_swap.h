/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:47:54 by syamada           #+#    #+#             */
/*   Updated: 2018/09/11 13:32:15 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

# define ABS_MID(x, len) ((x < (len / 2)) ? x : len - x)
# define LC 0x01
# define LV 0x02
# define LT 0x04

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

typedef struct	s_max
{
	int		value;
	int		i;
}				t_max;

typedef struct	s_maxob
{
	t_max	max;
	t_max	s_max;
	int		index;
	int		sec_i;
}				t_maxob;

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

typedef struct	s_object
{
	int			*arr;
	int			len;
	int			inc;
	int			i_target;
	int			target;
	int			sec_target;
	int			offset;
	t_op		op;
}				t_object;

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
int				search_index(t_stack *stack, int target);
t_stack			*copy_stack(t_stack *stack);

/*
** oplist funcs
*/

t_oplist		*newoplist(t_op op);
void			add_oplist(t_oplist **oplist, t_op op);
int				oplist_len(t_oplist *oplist);
t_oplist		*rev_oplist(t_oplist *oplist);
void			print_oplist(t_oplist *oplist);
void			oplistdel(t_oplist **oplist);

/*
** shared funcs
*/

int				create_stack(t_stack **stack, char **str, char option);
void			error_exit(char ***av, char option);
void			free_exit(char *str, char *input, char ***av, char option);

/*
** push_swap funcs
*/

t_oplist		*pick_algo(t_stack *a);
void			rough_sort_push(t_stack **a, t_stack **b,
								t_oplist **op, t_object *ob);
void			init_object(t_object **ob, t_stack *a);
void			get_target(t_stack **a, t_stack **b, t_oplist **op,
									t_object *ob);
t_object		*closest_target(t_stack *stack, t_object *ob);
t_oplist		*divide_sort(t_stack *a);
t_oplist		*small_sort(t_stack *a);

/*
** sorting helpers
*/

int				is_ascending(t_stack *stack);
int				is_descending(t_stack *stack);
int				max_index(t_stack *stack, t_maxob *mob);
int				min_index(t_stack *stack, int *index);
void			max_top(t_stack **a, t_stack **b, t_oplist **op);
void			min_top(t_stack **a, t_stack **b, t_oplist **op);
void			quick_sort(int **input, int left, int right);
int				*sort_stack_with_quick(t_stack *stack, t_object **ob);

/*
** checker funcs
*/

char			**check_option(int *argc, char **argv, char *option);
void			dispatcher(t_stack **a, t_stack **b, char *input,
							char option);
void			check(char **input, t_stack *a, char option);
char			**read_instruction(char option, char ***av);
int				is_valid(char *str);
void			free_input(char ***input);

#endif
