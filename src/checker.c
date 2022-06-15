/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:46:44 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/15 10:24:29 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_check(t_stack *a, t_stack *b)
{
	if (check_index(a) && is_empty(b))
	{
		free(a->arr);
		free(b->arr);
		write(1, "\033[32mOK\n", 8);
		exit(EXIT_SUCCESS);
	}
	else
	{
		free(a->arr);
		free(b->arr);
		write(1, "\033[31mKO\n", 8);
		exit(EXIT_FAILURE);
	}
}

void	operation_b(t_stack *a, t_stack *b, char *input)
{
	if (ft_strcmp(input, "sa"))
		sa(a);
	else if (ft_strcmp(input, "sb"))
		sb(b);
	else if (ft_strcmp(input, "ss"))
		ss(a, b);
	else if (ft_strcmp(input, "pa"))
		pa(a, b);
	else if (ft_strcmp(input, "pb"))
		pb(a, b);
	else if (ft_strcmp(input, "ra"))
		ra(a);
	else if (ft_strcmp(input, "rb"))
		rb(b);
	else if (ft_strcmp(input, "rr"))
		rr(a, b);
	else if (ft_strcmp(input, "rra"))
		rra(a);
	else if (ft_strcmp(input, "rrb"))
		rrb(b);
	else if (ft_strcmp(input, "rrr"))
		rrr(a, b);
}

char	*get_trim(int fd)
{
	char	*input;
	char	*ret;

	input = get_next_line(fd);
	ret = ft_strtrim(input, "\n");
	free(input);
	input = NULL;
	return (ret);
}

void	check_it_out(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = get_trim(0);
	while (operation)
	{
		operation_b(a, b, operation);
		free(operation);
		operation = NULL;
		operation = get_trim(0);
	}
	free(operation);
	operation = NULL;
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	pharse(&a, argv);
	is_dup(&a);
	make_b(&b, a.capacity);
	check_it_out(&a, &b);
	print_check(&a, &b);
	return (0);
}
