/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:34:36 by astachni          #+#    #+#             */
/*   Updated: 2023/02/22 16:16:00 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	take_mean(t_list *stack)
{
	t_list	*tmp;
	int		mean;

	mean = 0;
	tmp = stack;
	while (tmp)
	{
		mean += *(int *)tmp->content;
		tmp = tmp->next;
	}
	mean = mean / ft_lstsize(stack);
	return (mean);
}

int	mean_verif_max(t_list **stack_a, int mean)
{
	int		nb;
	t_list	*temp;

	nb = 0;
	temp = (*stack_a);
	while (temp)
	{
		if (*(int *)temp->content >= mean)
			nb += 1;
		temp = temp->next;
	}
	if (nb == 0)
		return (0);
	return (1);
}

int	mean_verif_min(t_list **stack_a, int mean)
{
	int		nb;
	t_list	*temp;

	nb = 0;
	temp = (*stack_a);
	while (temp)
	{
		if (*(int *)temp->content < mean)
			nb += 1;
		temp = temp->next;
	}
	if (nb == 0)
		return (0);
	return (1);
}
