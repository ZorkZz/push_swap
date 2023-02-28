/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:18:30 by astachni          #+#    #+#             */
/*   Updated: 2023/02/28 23:57:00 by astachni         ###   ########.fr       */
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
			if (parsing_error(argv[i][j], argv[i][j + 1], argv[i][j - 1]) == 1)
				exit (1);
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
				error(lst);
			temp = temp->next;
		}
		iter++;
		temp = (*lst);
	}
}

void	verify_str(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i] && strs[i][j])
		{
			if ((j == 0 || j == (int)ft_strlen(strs[i]))
				&& strs[i][j] != '-' && ft_isdigit(strs[i][j]) == 0)
				error_pars(strs);
			if (j != 0 && j < (int)ft_strlen(strs[i]))
			{
				if (parsing_error(strs[i][j], strs[i][j + 1], \
					strs[i][j - 1]) == 1)
				{
					free_strs(strs);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	arg_char(t_list **lst, char **argv)
{
	char	**args;
	int		i;

	args = ft_split(argv[1], ' ');
	verify_str(args);
	i = 0;
	while (args && args[i])
	{
		if ((long)ft_atoi(args[i]) != ft_atol(args[i]))
			error_pars(args);
		add_to_stack(lst, ft_atoi(args[i]));
		free (args[i]);
		i++;
	}
	free(args);
}

void	parsing(t_list **lst, char **argv, int argc)
{
	int		iter;

	*lst = NULL;
	if (argc == 2)
		arg_char(lst, argv);
	if (argc > 2)
	{
		verif_number(argv);
		iter = 1;
		while (argv[iter])
		{
			if (ft_strncmp(argv[iter], "", ft_strlen(argv[iter])) == 0)
				error(lst);
			add_to_stack(lst, ft_atoi(argv[iter]));
			iter++;
		}
	}
	if (argc > 2)
		verif_double(lst);
}
