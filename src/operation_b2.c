/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:28:11 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/14 18:31:36 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ra(t_stack *a)
{
	if (rotate(a) == 0)
		return (0);
	return (1);
}

int	rb(t_stack *b)
{
	if (rotate(b) == 0)
		return (0);
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) == 0 || rotate(b) == 0)
		return (0);
	return (1);
}

int	rra(t_stack *a)
{
	if (reverse_rotate(a) == 0)
		return (0);
	return (1);
}

int	rrb(t_stack *b)
{
	if (reverse_rotate(b) == 0)
		return (0);
	return (1);
}
