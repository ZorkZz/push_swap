/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:35:25 by astachni          #+#    #+#             */
/*   Updated: 2023/02/05 17:24:43 by astachni         ###   ########.fr       */
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

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	(void)stack_b;
	size_a = ft_lstsize(*stack_a);
	if (size_a < 6)
	{
		reverse(stack_a, 'a');
	}
}
