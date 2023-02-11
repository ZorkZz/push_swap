/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:23:10 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/11 16:40:25 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// decale tous d'une position vers le bas pour les 2 stacks
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a, 'd');
	reverse(stack_b, 'd');
	ft_printf("rrr\n");
}

// decale tous d'une position vers le haut pour les 2 stacks
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'd');
	rotate(stack_b, 'd');
	ft_printf("rr\n");
}

// interverti les 2 premiers elements pour les 2 stacks
void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 'd');
	swap(stack_b, 'd');
	ft_printf("ss\n");
}
