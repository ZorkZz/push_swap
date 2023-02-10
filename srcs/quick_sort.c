/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:05:31 by astachni          #+#    #+#             */
/*   Updated: 2023/02/10 17:11:42 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	max;

	max = max_pos(*stack_a);
	if (max == 1)
		rotate(stack_a, 'a');
	if (max == 2)
		reverse(stack_a, 'a');
	if (*(int *)(*stack_a)->content >
			*(int *)(*stack_a)->next->content)
		swap(stack_a, 'a');
	return ;
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = min_pos(*stack_a);
	if (min == 3 || min == 2)
	{
		if (min == 3)
			rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	if (min == 4)
		reverse (stack_a, 'a');
	push(stack_b, stack_a, 'b');
	sort_3(stack_a);
	push(stack_a, stack_b, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = min_pos(*stack_a);
	if (min == 3 || min == 2)
	{
		if (min == 3)
			rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	if (min == 4 || min == 5)
	{
		if (min == 4)
			reverse (stack_a, 'a');
		reverse (stack_a, 'a');
	}
	push(stack_b, stack_a, 'b');
	sort_4(stack_a, stack_b);
	push(stack_a, stack_b, 'a');
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	int		size_a;

	size_a = ft_lstsize(*stack_a);
	if (size_a == 3)
		sort_3(stack_a);
	else if (size_a == 4)
		sort_4(stack_a, stack_b);
	else if (size_a == 5)
		sort_5(stack_a, stack_b);
}
