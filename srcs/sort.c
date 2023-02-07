/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:35:25 by astachni          #+#    #+#             */
/*   Updated: 2023/02/07 17:20:20 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// void	take_a_to_b(t_list **stack_a, t_list **stack_b)
// {
// 	ssize_t	min;

// 	min = min_pos(*stack_a);
// 	if (min == 3 || min == 2)
// 	{
// 		if (min == 3)
// 			rotate(stack_a, 'a');
// 		swap(stack_a, 'a');
// 	}
// 	if (min == 4)
// 		reverse (stack_a, 'a');
// 	push(stack_b, stack_a, 'b');
// }

void	sort_3(t_list **stack_a)
{
	ssize_t	max;

	max = max_pos(*stack_a);
	if (max == 1)
		rotate(stack_a, 'a');
	if (max == 2)
		reverse(stack_a, 'a');
	if (*(ssize_t *)(*stack_a)->content >
			*(ssize_t *)(*stack_a)->next->content)
		swap(stack_a, 'a');
	return ;
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	ssize_t	min;

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
	ssize_t	min;

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
}

void	sort(t_list **stack_a, t_list **stack_b)
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
