/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:41 by astachni          #+#    #+#             */
/*   Updated: 2023/02/07 16:37:46 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

ssize_t	ft_lstpos(t_list *lst, ssize_t num)
{
	ssize_t	i;
	t_list	*temp;

	temp = lst;
	i = 1;
	while (temp)
	{
		if (*(ssize_t *)temp->content == num)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

ssize_t	max_pos(t_list *lst)
{
	ssize_t	max;
	t_list	*temp;
	t_list	*temp1;
	ssize_t	pos;

	temp = lst;
	max = *(ssize_t *)temp->content;
	while (temp)
	{
		if (*(ssize_t *)temp->content >= max)
		{
			max = *(ssize_t *)temp->content;
			temp1 = lst;
			pos = ft_lstpos(temp1, max);
		}
		temp = temp->next;
	}
	return (pos);
}


ssize_t	min_pos(t_list *lst)
{
	ssize_t	min;
	t_list	*temp;
	t_list	*temp1;
	ssize_t	pos;

	temp = lst;
	min = *(ssize_t *)temp->content;
	while (temp)
	{
		if (*(ssize_t *)temp->content <= min)
		{
			min = *(ssize_t *)temp->content;
			temp1 = lst;
			pos = ft_lstpos(temp1, min);
		}
		temp = temp->next;
	}
	return (pos);
}