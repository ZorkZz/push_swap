/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:58:38 by astachni          #+#    #+#             */
/*   Updated: 2023/02/22 17:52:52 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	do_radix(t_list **stack_a, t_list **stack_b, int i, int size);
void		replace_number(t_list **stack_a);

void	radix(t_list **stack_a, t_list **stack_b)
{
	const int	size = ft_lstsize(*stack_a);
	int			i;

	i = 0;
	while (is_sorted(stack_a) == 1)
	{
		do_radix(stack_a, stack_b, i, size);
		i++;
	}
}

static void	do_radix(t_list **stack_a, t_list **stack_b, int i, const int size)
{
	int			j;

	replace_number(stack_a);
	j = 0;
	while (j < size)
	{
		if ((*(int *)(*stack_a)->number >> i) % 2 == 0)
			push(stack_b, stack_a, 'b');
		else
			rotate(stack_a, 'a');
		j++;
	}
	while (*stack_b != NULL)
		push(stack_a, stack_b, 'a');
}

void	replace_number(t_list **stack_a)
{
	t_list	*temp0;
	t_list	*temp1;
	int		i;
	int		*nbr;

	temp0 = *stack_a;
	while (temp0)
	{
		i = 0;
		temp1 = *stack_a;
		while (temp1)
		{
			if (*(int *)temp1->content > *(int *)temp0->content)
				i++;
			temp1 = temp1->next;
		}
		nbr = malloc(sizeof(int));
		*nbr = i;
		temp0->number = nbr;
		temp0 = temp0->next;
	}
}
