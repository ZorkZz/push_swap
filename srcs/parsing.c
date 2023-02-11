/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:18:30 by astachni          #+#    #+#             */
/*   Updated: 2023/02/11 17:05:02 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	verif_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
			{
				ft_putendl_fd("error\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	verif_double(t_list **lst)
{
	t_list	*temp;
	int		number;
	int		iter;

	temp = (*lst);
	number = *(int *)temp->content;
	iter = 0;
	while (temp && temp->next && iter < ft_lstsize(temp))
	{
		temp = inter_n_times_change(temp, iter);
		number = *(int *)temp->content;
		temp = inter_n_times_change(temp, 1);
		while (temp)
		{
			if (number == *(int *)temp->content)
			{
				ft_putendl_fd("error\n", 2);
				exit(1);
			}
			temp = temp->next;
		}
		iter++;
		temp = (*lst);
	}
}

void	parsing(t_list **lst, char **argv, int argc)
{
	int		iter;

	*lst = NULL;
	verif_number(argv);
	if (argc > 2)
	{
		iter = 1;
		while (argv[iter])
		{
			add_to_stack(lst, ft_atoi(argv[iter]));
			iter++;
		}
	}
	verif_double(lst);
}
