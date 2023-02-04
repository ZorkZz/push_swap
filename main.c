/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:18:28 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/04 18:25:55 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;

	stack_b = NULL;
	parsing(&stack_a, argv, argc);
	temp = stack_a;
	ft_printf("------");
	while (temp)
	{
		ft_printf("%d, ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("------\n");
	swap(&stack_a);
	temp = stack_a;
	ft_printf("------");
	while (temp)
	{
		ft_printf("%d, ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("------\n");
	push(&stack_b, &stack_a);
	temp = stack_a;
	ft_printf("------");
	while (temp)
	{
		ft_printf("%d, ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("------\n");
	temp = stack_b;
	ft_printf("------");
	while (temp)
	{
		ft_printf("%d, ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("------\n");
	free_lst(stack_a);
}
