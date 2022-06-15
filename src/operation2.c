/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:44:48 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/14 18:31:08 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ra(t_stack *a)
{
	if (rotate(a) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		return (0);
	}
	return (1);
}

int	rb(t_stack *b)
{
	if (rotate(b) == 0)
	{
		ft_putstr_fd("rb\n", 1);
		return (0);
	}
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) == 0 || rotate(b) == 0)
	{
		ft_putstr_fd("rr\n", 1);
		return (0);
	}
	return (1);
}

int	rra(t_stack *a)
{
	if (reverse_rotate(a) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		return (0);
	}
	return (1);
}

int	rrb(t_stack *b)
{
	if (reverse_rotate(b) == 0)
	{
		ft_putstr_fd("rrb\n", 1);
		return (0);
	}
	return (1);
}
