/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:30:42 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/13 09:45:32 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(t_stack *from)
{
	int	temp;

	temp = top_stack(from);
	from->arr[from->size - 1] = from->arr[from->size - 2];
	from->arr[from->size - 2] = temp;
	return (0);
}

int	push(t_stack *from, t_stack *to)
{
	int	temp;

	temp = top_stack(from);
	if (!is_empty(from))
	{
		from->size--;
		to->arr[to->size] = temp;
		to->size++;
	}
	return (0);
}

int	rotate(t_stack *from)
{
	int	temp;
	int	i;

	i = from->size - 1;
	temp = top_stack(from);
	while (i > 0)
	{
		from->arr[i] = from->arr[i - 1];
		i--;
	}
	from->arr[0] = temp;
	return (0);
}

int	reverse_rotate(t_stack *from)
{
	int	temp;
	int	i;

	i = 0;
	temp = bottom_stack(from);
	while (i < from->size - 1)
	{
		from->arr[i] = from->arr[i + 1];
		i++;
	}
	from->arr[from->size - 1] = temp;
	return (0);
}

int	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
