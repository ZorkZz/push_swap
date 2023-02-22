/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:58:38 by astachni          #+#    #+#             */
/*   Updated: 2023/02/22 19:31:03 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	do_radix(t_list **stack_a, t_list **stack_b, int i, int size);
static void	replace_number(t_list *stack_a);

void	radix(t_list **stack_a, t_list **stack_b)
{
	const int	size = ft_lstsize(*stack_a);
	int			i;

	replace_number(*stack_a);
	i = 0;
	while (is_sorted(stack_a) == 1)
	{
		do_radix(stack_a, stack_b, i, size);
		i++;
	}
}

static void	do_radix(t_list **stack_a, t_list **stack_b, int i, const int size)
{
	int			j;

	j = 0;
	while (j < size)
	{
		if (((*stack_a)->number >> i) % 2 == 0)
			push(stack_b, stack_a, 'b');
		else
			rotate(stack_a, 'a');
		j++;
	}
	while (*stack_b != NULL)
		push(stack_a, stack_b, 'a');
}

static void	replace_number(t_list *stack_a)
{
	t_list	*stack_a_start;
	t_list	*temp1;
	int		i;

	stack_a_start = stack_a;
	while (stack_a)
	{
		i = 0;
		temp1 = stack_a_start;
		while (temp1)
		{
			if (*(int *)temp1->content < *(int *)stack_a->content)
				i++;
			temp1 = temp1->next;
		}
		stack_a->number = i;
		stack_a = stack_a->next;
	}
}
