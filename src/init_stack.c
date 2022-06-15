/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:22:27 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/14 13:04:07 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_index(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	make_a(t_stack *a, int num)
{
	int	*temp;
	int	i;

	i = a->size;
	if (a->size >= a->capacity)
	{
		temp = malloc(sizeof(int) * (a->capacity * 2));
		if (temp == 0)
			print_error();
		ft_memcpy(temp, a->arr, (a->size * sizeof(int)));
		free(a->arr);
		a->arr = temp;
		a->capacity *= 2;
	}
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = num;
	a->size++;
}

void	indexing(t_stack *a)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = (int *)malloc(sizeof(int) * a->size);
	if (temp == NULL)
		print_error();
	while (i < a->size)
	{
		j = 0;
		temp[i] = 0;
		while (j < a->size)
		{
			if (a->arr[i] > a->arr[j])
					temp[i]++;
			j++;
		}
		i++;
	}
	free(a->arr);
	a->arr = NULL;
	a->arr = temp;
}

void	make_b(t_stack *b, int size)
{
	b->arr = malloc(sizeof(int) * size);
	if (b->arr == 0)
		print_error();
	b->size = 0;
	b->capacity = size;
}

void	init_stack(t_stack *stack)
{
	int	num;

	num = 500;
	stack->arr = malloc(sizeof(int) * num);
	if (stack->arr == 0)
		print_error();
	stack->size = 0;
	stack->capacity = num;
}
