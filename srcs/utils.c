/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:16:10 by astachni          #+#    #+#             */
/*   Updated: 2023/02/05 17:18:18 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_lst(t_list *lst)
{
	while (lst)
	{
		free(lst->content);
		lst = lst->next;
	}
	if (lst)
		free(lst);
}

void	add_to_stack(t_list **lst, int i)
{
	int		*content;
	t_list	*new_node;

	content = malloc(sizeof(int));
	*content = i;
	new_node = ft_lstnew(content);
	ft_lstadd_back(lst, new_node);
}

void	inter_n_times_change(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n && lst)
	{
		lst = lst->next;
		i++;
	}
}

void	inter_n_times_no_change(t_list **lst, int n)
{
	int		i;
	t_list	*copy;

	copy = *lst;
	i = 0;
	while (i < n && copy)
	{
		copy = copy->next;
		i++;
	}
}
