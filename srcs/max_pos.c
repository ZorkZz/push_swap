/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:41 by astachni          #+#    #+#             */
/*   Updated: 2023/02/10 17:12:38 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_lstpos(t_list *lst, int num)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 1;
	while (temp)
	{
		if (*(int *)temp->content == num)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

int	max_pos(t_list *lst)
{
	int		max;
	t_list	*temp;
	t_list	*temp1;
	int		pos;

	temp = lst;
	max = *(int *)temp->content;
	while (temp)
	{
		if (*(int *)temp->content >= max)
		{
			max = *(int *)temp->content;
			temp1 = lst;
			pos = ft_lstpos(temp1, max);
		}
		temp = temp->next;
	}
	return (pos);
}

int	min_pos(t_list *lst)
{
	int		min;
	t_list	*temp;
	t_list	*temp1;
	int		pos;

	temp = lst;
	min = *(int *)temp->content;
	while (temp)
	{
		if (*(int *)temp->content <= min)
		{
			min = *(int *)temp->content;
			temp1 = lst;
			pos = ft_lstpos(temp1, min);
		}
		temp = temp->next;
	}
	return (pos);
}
