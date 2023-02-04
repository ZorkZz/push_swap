/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:18:28 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/04 12:19:02 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		iter;

	if (argc > 2)
	{
		iter = 1;
		while (argv[iter])
		{
			add_to_stack(&stack_a, ft_atoi(argv[iter]));
			iter++;
		}
		stack_b = stack_a;
		while (stack_b)
		{
			ft_printf("%d", *(int *)stack_b->content);
			stack_b = stack_b->next;
		}
	}
	else if (argc == 2)
	{
		return (0);
	}
	free_lst(stack_a);
}
