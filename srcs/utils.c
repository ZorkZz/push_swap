/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:16:10 by astachni          #+#    #+#             */
/*   Updated: 2023/02/21 17:00:00 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
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

t_list	*inter_n_times_change(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n && lst)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
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

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		free(strs[i++]);
	if (strs)
		free(strs);
}
