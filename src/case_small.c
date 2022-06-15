/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:09:22 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/14 11:11:34 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack *a)
{
	if (check_index(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->arr[0] > a->arr[2] && a->arr[1] > a->arr[0])
	{
		sa(a);
		ra(a);
	}
	else if (a->arr[2] > a->arr[1] && a->arr[0] > a->arr[2])
		sa(a);
	else if (a->arr[2] > a->arr[0] && a->arr[1] > a->arr[2])
		rra(a);
	else if (a->arr[0] > a->arr[1] && a->arr[2] > a->arr[0])
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

int	median(t_stack *a)
{
	int	i;
	int	t;
	int	k;

	i = 0;
	while (i < a->size)
	{
		t = 0;
		k = 0;
		while (t < a->size)
		{
			if (a->arr[t] - a->arr[i] > 0)
				k++;
			t++;
		}
		if (k == 2)
			return (a->arr[i]);
		i++;
	}
	return (1);
}

void	case_small(t_stack *a, t_stack *b)
{
	while (3 < a->size)
	{
		while (top_stack(a) >= median(a))
		{
			ra(a);
		}
		pb(a, b);
	}
	if (a->size == 3 || a->size == 2)
		sort(a);
	while (b->size > 0)
		pa(a, b);
	if (top_stack(a) > a->arr[a->size - 2])
		sa(a);
}

void	sorting(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		case_small(a, b);
	else
		case_large(a, b);
}
