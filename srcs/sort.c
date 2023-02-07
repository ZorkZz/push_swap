/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:35:25 by astachni          #+#    #+#             */
/*   Updated: 2023/02/07 16:38:13 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sort3(t_list **stack_a)
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

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		size_a;

	(void)stack_b;
	size_a = ft_lstsize(*stack_a);
	if (size_a == 3)
	{
		sort3(stack_a);
	}
	if (sort == 4)
	{
		
	}
}
