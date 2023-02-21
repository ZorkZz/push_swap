/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:35:25 by astachni          #+#    #+#             */
/*   Updated: 2023/02/21 18:17:46 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	mean_verif(t_list **stack_a, int mean, int nbr)
{
	int		nb;
	t_list	*temp;

	nb = 0;
	temp = (*stack_a);
	if (nbr == 1)
	{
		while (temp)
		{
			if (*(int *)temp->content >= mean)
				nb += 1;
			temp = temp->next;
		}
	}
	else
	{
		while (temp)
		{
			if (*(int *)temp->content < mean)
				nb += 1;
			temp = temp->next;
		}
	}
	if (nb == 0)
		return (0);
	return (1);
}

void	first_sort(t_list **stack_a, t_list **stack_b)
{
	int			mean;
	t_list		*temp;
	int			iter;

	(void)stack_b;
	mean = 0;
	temp = *stack_a;
	while (temp)
	{
		mean += *(int *)temp->content;
		temp = temp->next;
	}
	mean = mean / ft_lstsize(*stack_a);
	temp = *stack_a;
	while (mean_verif(&temp, mean, 1) != 0)
	{
		while (*(int *)temp->content >= mean)
			push(stack_b, &temp, 'b');
		if (*(int *)temp->content < mean)
		{
			if (max_pos(temp) > ft_lstsize(temp) / 2)
				reverse(&temp, 'a');
			else
				rotate(&temp, 'a');
		}
		iter += 1;
	}
	*stack_a = temp;
}

void	a_t_b(t_list **stack_a, t_list **stack_b)
{
	int			mean;
	t_list		*temp;

	mean = 0;
	temp = *stack_a;
	while (temp)
	{
		mean += *(int *)temp->content;
		temp = temp->next;
	}
	mean = mean / ft_lstsize(*stack_a);
	temp = *stack_a;
	while (mean_verif(&temp, mean, 2) != 0)
	{
		while (*(int *)temp->content < mean)
			push(stack_b, &temp, 'b');
		if (*(int *)temp->content >= mean)
		{
			if (max_pos(temp) > ft_lstsize(temp) / 2)
				reverse(&temp, 'a');
			else
				rotate(&temp, 'a');
		}
	}
	*stack_a = temp;
	if (max_pos(*stack_a) == 1)
		rotate(stack_a, 'a');
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	first_sort(stack_a, stack_b);
	while (stack_b && (*stack_b)->next)
	{
		if (max_pos(*stack_b) == 1)
			push(stack_a, stack_b, 'a');
		else if (max_pos(*stack_b) > ft_lstsize(*stack_b) / 2)
			reverse(stack_b, 'b');
		else
			rotate(stack_b, 'b');
	}
	push(stack_a, stack_b, 'a');
	a_t_b(stack_a, stack_b);
	while (*stack_b && (*stack_b)->next)
	{
		if (max_pos(*stack_b) == 1)
			push(stack_a, stack_b, 'a');
		else if (max_pos(*stack_b) > ft_lstsize(*stack_b) / 2)
			reverse(stack_b, 'b');
		else
			rotate(stack_b, 'b');
	}
	push(stack_a, stack_b, 'a');
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a) != 0)
		quick_sort(stack_a, stack_b);
	if (is_sorted(stack_a) != 0)
		big_sort(stack_a, stack_b);
}
