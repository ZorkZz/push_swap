/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:21:39 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/13 16:43:52 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// interverti les 2 premiers elements
void	swap(t_list **stack, char c)
{
	t_list	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
}

//premier element de la stack va dans lautre stack
void	push(t_list **dst, t_list **src, char c)
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
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
}

// decale tous d'une position vers le haut
void	rotate(t_list **stack, char c)
{
	t_list	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	ft_lstlast(tmp)->next = *stack;
	(*stack)->next = NULL;
	(*stack) = tmp;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
}

// decale tous d'une position vers le bas
void	reverse(t_list **stack, char c)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		size;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	tmp1 = (*stack);
	size = ft_lstsize(tmp1);
	tmp = ft_lstlast(tmp);
	tmp->next = tmp1;
	tmp1 = inter_n_times_change(tmp1, size - 2);
	tmp1->next = NULL;
	(*stack) = tmp;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else
		ft_putendl_fd("rrb", 1);
}
