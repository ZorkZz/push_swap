/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:21:39 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/04 17:53:45 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// interverti les 2 premiers elements
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

//premier element de la stack va dans lautre stack
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

// decale tous d'une position vers le haut
void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp1 = (*stack);
	tmp = (*stack);
	tmp1 = tmp1->next;
	(*stack) = tmp1;
	ft_lstlast(tmp1)->next = tmp;
	tmp->next = NULL;
}

// decale tous d'une position vers le bas
void	reverse(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		size;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	tmp1 = (*stack);
	*stack = ft_lstlast(*stack);
	size = ft_lstsize(tmp);
	(*stack)->next = tmp1;
	tmp = tmp1;
	while (size >= 0)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
}
