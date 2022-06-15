/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:02:05 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/14 09:41:22 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
}	t_stack;

void	print_error(void);
int		top_stack(t_stack *stack);
int		bottom_stack(t_stack *stack);

//stack and pharse
void	init_stack(t_stack *stack);
void	pharse(t_stack *stack, char **argv);
void	is_dup(t_stack *stack);
int		check_index(t_stack *a);
void	indexing(t_stack *a);
void	make_a(t_stack *a, int num);
void	make_b(t_stack *b, int size);
int		is_empty(t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);

// operation team
int		swap(t_stack *from);
int		push(t_stack *from, t_stack *to);
int		rotate(t_stack *from);
int		reverse_rotate(t_stack *from);

// operations
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrr(t_stack *a, t_stack *b);

//sorting
void	sorting(t_stack *a, t_stack *b);
void	case_large(t_stack *a, t_stack *b);
#	endif
