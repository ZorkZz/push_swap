/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:18:28 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/07 15:08:09 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	//change compilateur
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;

	stack_b = NULL;
	parsing(&stack_a, argv, argc);
	temp = stack_a;
	ft_printf("------");
	while (temp)
	{
		ft_printf("\n%d\n", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("------\n");
	sort(&stack_a, &stack_b);
	temp = stack_a;
	ft_printf("------\n");
	while (temp)
	{
		ft_printf("\n%d\n", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("------\n");
}
