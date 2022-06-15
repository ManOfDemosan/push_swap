/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pharse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:06:36 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/09 16:14:49 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	check_num(char **arr)
{
	int	i;
	int	j;

	i = 0;
	if (!arr || *arr == NULL)
		print_error();
	while (arr[i] != 0)
	{
		j = 0;
		while (arr[i][j] != 0)
		{
			if (!((arr[i][j] >= '0' && arr[i][j] <= '9') || \
				(arr[i][j] == '+' || arr[i][j] == '-')))
				print_error();
			if ((arr[i][j] == '+' || arr[i][j] == '-') && arr[i][j + 1] == '\0')
				print_error();
			if (j > 0 && (arr[i][j] == '+' || arr[i][j] == '-'))
				print_error();
			j++;
		}
		i++;
	}
}

long long	ps_atoi(char *arr)
{
	long long	digit;
	int			button;

	digit = 0;
	button = 1;
	while ((9 <= *arr && *arr <= 13) || *arr == 32)
		arr++;
	if (*arr == '+' || *arr == '-')
	{
		if (*arr == '-')
			button = -1;
		arr++;
	}
	while ((*arr >= '0') && (*arr <= '9'))
	{
		digit *= 10;
		digit += (*arr - '0');
		arr++;
	}
	return (digit * button);
}

void	is_dup(t_stack *stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < stack->size)
	{
		temp = stack->arr[i];
		j = i + 1;
		while (j < stack->size)
		{
			if (temp == stack->arr[j++])
				print_error();
		}
		i++;
	}
}

void	pharse(t_stack *stack, char **argv)
{
	char		**arr;
	int			i;
	int			j;
	long long	num;

	i = 1;
	while (argv[i] != 0)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		if (arr[j] == NULL)
			print_error();
		while (arr[j] != 0)
		{
			num = ps_atoi(arr[j]);
			if (num > 2147483647 || num < -2147483648)
				print_error();
			check_num(arr);
			make_a(stack, (int)num);
			j++;
		}
		free_split(arr);
	}
}
