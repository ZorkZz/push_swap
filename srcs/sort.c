/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:35:25 by astachni          #+#    #+#             */
/*   Updated: 2023/02/10 19:00:30 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	first_sort(t_list **stack_a, t_list **stack_b)
{
	int			mean;
	t_list		*temp;
	const int	size = ft_lstsize(*stack_a);
	int			iter;

	(void)stack_b;
	mean = 0;
	temp = *stack_a;
	while (temp)
	{
		mean += *(int *)temp->content;
		temp = temp->next;
	}
	mean = mean / size;
	temp = *stack_a;
	iter = 0;
	while (iter <= size)
	{
		while (*(int *)temp->content <= mean)
			push(stack_b, &temp, 'b');
		if (*(int *)temp->content > mean)
			rotate(&temp, 'a');
		iter += 1;
	}
	*stack_a = temp;
}

void	a_t_b(t_list **stack_a, t_list **stack_b)
{
	int			mean;
	t_list		*temp;
	const int	size = ft_lstsize(*stack_a);
	int			iter;

	(void)stack_b;
	mean = 0;
	temp = *stack_a;
	while (temp)
	{
		mean += *(int *)temp->content;
		temp = temp->next;
	}
	mean = mean / size;
	temp = *stack_a;
	iter = 0;
	while (iter <= size)
	{
		while (*(int *)temp->content > mean)
			push(stack_b, &temp, 'b');
		if (*(int *)temp->content <= mean)
		{
			if (max_pos(temp) < (size / 2))
				rotate(&temp, 'b');
			else
				reverse(&temp, 'b');
		}
		iter += 1;
	}
	*stack_a = temp;
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	first_sort(stack_a, stack_b);
	while (stack_b && (*stack_b)->next)
	{
		if (ft_lstsize(*stack_b) > 1)
		{
			while (max_pos(*stack_b) != 1)
			{
				if (max_pos(*stack_b) < (ft_lstsize(*stack_b) / 2))
					rotate(stack_b, 'b');
				else
					reverse(stack_b, 'b');
			}
		}
		push(stack_a, stack_b, 'a');
	}
	push(stack_a, stack_b, 'a');
	a_t_b(stack_a, stack_b);
	while (stack_b && (*stack_b)->next)
	{
		if (ft_lstsize(*stack_b) > 0)
		{
			while (min_pos(*stack_b) != 1)
				reverse(stack_b, 'b');
		}
		push(stack_a, stack_b, 'a');
	}
	push(stack_a, stack_b, 'a');
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	quick_sort(stack_a, stack_b);
	if (is_sorted(stack_a) != 0)
		big_sort(stack_a, stack_b);
}
