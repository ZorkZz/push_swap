/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:18:28 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/20 16:09:06 by astachni         ###   ########.fr       */
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
	// 	ft_putnbr_fd(*(int *)stack_a->content, 1);
	// 	ft_putchar_fd('\n', 1);
	// 	stack_a = stack_a->next;
	// }
	while (stack_a)
	{
		free(stack_a->content);
		stack_a = stack_a->next;
	}
}
