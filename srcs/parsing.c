/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:18:30 by astachni          #+#    #+#             */
/*   Updated: 2023/02/10 19:11:56 by astachni         ###   ########.fr       */
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
				ft_printf("error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	//verif_douple(argv);
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
}
