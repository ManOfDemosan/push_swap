/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:37:32 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/10 13:57:13 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sa(t_stack *a)
{
	if (swap(a) == 0)
	{
		ft_putstr_fd("sa\n", 1);
		return (0);
	}
	return (1);
}

int	sb(t_stack *b)
{
	if (swap(b) == 0)
	{
		ft_putstr_fd("sb\n", 1);
		return (0);
	}
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	if (swap(a) == 0 || swap(b) == 0)
	{
		ft_putstr_fd("ss\n", 1);
		return (0);
	}
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	if (push(b, a) == 0)
	{
		ft_putstr_fd("pa\n", 1);
		return (0);
	}
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	if (push(a, b) == 0)
	{
		ft_putstr_fd("pb\n", 1);
		return (0);
	}
	return (1);
}
