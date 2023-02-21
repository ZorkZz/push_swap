/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:18:28 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/21 18:18:04 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	parsing(&stack_a, argv, argc);
	sort(&stack_a, &stack_b);
	// while (stack_a)
	// {
	// 	ft_printf("%d\n", *(int *)stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	// ft_printf("--------------------\n");
	// while (stack_b)
	// {
	// 	ft_printf("%d\n", *(int *)stack_b->content);
	// 	stack_b = stack_b->next;
	// }
	ft_lstclear(&stack_a, free);
}
