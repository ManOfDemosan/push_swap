/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:28:14 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/14 18:30:30 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sa(t_stack *a)
{
	if (swap(a) == 0)
		return (0);
	return (1);
}

int	sb(t_stack *b)
{
	if (swap(b) == 0)
		return (0);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	if (swap(a) == 0 || swap(b) == 0)
		return (0);
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	if (push(b, a) == 0)
		return (0);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	if (push(a, b) == 0)
		return (0);
	return (1);
}
