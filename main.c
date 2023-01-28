/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:18:28 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/28 20:36:23 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	do_stuff(t_list **lst, int i)
{
	int		*content;
	t_list	*new_node;

	content = malloc(sizeof(int));
	*content = i;
	new_node = ft_lstnew(content);
	ft_lstadd_back(lst, new_node);
}

void	inter_n_times_simple(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n && lst)
	{
		lst = lst->next;
		i++;
	}
}

void	inter_n_times_double(t_list **lst, int n)
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

int	main(void)
{
	t_list	*lst;
	t_list	*temp;
	int		*content;

	lst = NULL;
	do_stuff(&lst, 0);
	content = lst->content;
	printf("%d\n", *content);
	do_stuff(&lst, 4);
	content = lst->next->content;
	printf("%d\n", *content);
	do_stuff(&lst, -2);
	content = lst->next->next->content;
	printf("%d\n", *content);
	printf("______________________________________\n");
	printf("SWAP\n");
	swap(&lst);
	temp = lst;
	while (temp)
	{
		printf("%d\n", *(int *)temp->content);
		temp->next;
	}
	printf("______________________________________\n");
	printf("ROTATE\n");
	rotate(&lst);
	temp = lst;
	while (temp)
	{
		printf("%d\n", *(int *)temp->content);
		temp->next;
	}
	printf("______________________________________\n");
	printf("REVERSE\n");
	reverse(&lst);
	temp = lst;
	while (temp)
	{
		printf("%d\n", *(int *)temp->content);
		temp->next;
	}
}
