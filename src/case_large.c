/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:17:43 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/14 17:33:43 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_to_b(t_stack *a, t_stack *b, int chunk, int i)
{
	int	size;

	size = a->size - 1;
	while (!is_empty(a))
	{
		if (top_stack(a) <= i)
		{
			pb(a, b);
			i++;
		}
		else if (top_stack(a) > i && top_stack(a) <= i + chunk)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (top_stack(a) > (i + chunk))
		{
			if (i < a->size / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
		size--;
	}
}
/* top이 i 보다 작을때 넘김
	 i + 15 사이일때만 b로 넘기고 한번 뒤집음
	 if (i < index && index <= i + chunk)
	 i + chunk 보다 클때 b로 안넘김
*/

void	sort_b(t_stack *b, int size)
{
	int	i;

	i = 0;
	while (i < b->size && b->arr[i] != size)
		i++;
	while (i < b->size / 2 && i >= 0)
	{
		rrb(b);
		i--;
	}
	while (i >= b->size / 2 && i < b->size - 1)
	{
		rb(b);
		i++;
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	size;

	size = b->size - 1;
	while (!is_empty(b))
	{
		sort_b(b, size);
		pa(a, b);
		size--;
	}
}
	/* while문으로 
	i 가 size 보다 작으면서 b스택이 size 가 아닐때
	반으로 나눠서 i가 size/2보다 작으면서 0보다 클때 == 0<=i<size/2
	반으로 나눠서 i가 size/2보다 크면서 size - 1 보다 작을때 size/2 <= i < size - 1
	*/

void	case_large(t_stack *a, t_stack *b)
{
	int	chunk;
	int	x;
	int	i;

	i = 0;
	x = a->size;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	a_to_b(a, b, chunk, i);
	b_to_a(a, b);
}
