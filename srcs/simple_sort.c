/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:21:39 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/28 20:39:55 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!dst || !src || !*src)
		return ;
	tmp_b = (*src)->next;
	(*src)->next = *dst;
	tmp_a = *src;
	*src = tmp_b;
	*dst = tmp_a;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		size;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp1 = (*stack);
	tmp = (*stack);
	tmp1 = tmp1->next;
	(*stack) = tmp1;
	size = ft_lstsize((*stack));
	ft_lstlast(tmp1)->next = tmp;
	tmp->next = NULL;
}

void	reverse(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		size;
	int		x;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	tmp1 = (*stack);
	*stack = ft_lstlast(*stack);
	size = ft_lstsize(tmp);
	(*stack)->next = tmp1;
	x = 0;
	tmp = tmp1;
	while (size >= 0)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
}
