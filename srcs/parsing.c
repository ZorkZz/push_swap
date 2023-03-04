/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:18:30 by astachni          #+#    #+#             */
/*   Updated: 2023/03/04 16:27:11 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	verif_number(int argc, char **argv, t_list **lst)
{
	int		i;
	int		j;
	char	**arg_cpy;

	arg_cpy = ft_strsdup(argc, argv);
	i = 1;
	while (arg_cpy[i])
	{
		j = 0;
		while (arg_cpy[i][j])
		{
			if ((j == 0 || j == (int)ft_strlen(arg_cpy[i]))
				&& arg_cpy[i][j] != '-' && ft_isdigit(arg_cpy[i][j]) == 0)
				error_pars(arg_cpy, lst);
			if ((j != 0 && j != (int)ft_strlen(arg_cpy[i])) && parsing_error(
					arg_cpy[i][j], arg_cpy[i][j + 1], arg_cpy[i][j - 1]) == 1)
			{
				free_strs(arg_cpy);
				exit(1);
			}
			j++;
		}
		i++;
	}
	free_strs(arg_cpy);
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

void	verify_str(char **strs, t_list **lst)
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
				error_pars(strs, lst);
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
	verify_str(args, lst);
	i = 0;
	while (args && args[i])
	{
		if ((long)ft_atoi(args[i]) != ft_atol(args[i]))
			error_pars(args, lst);
		add_to_stack(lst, ft_atoi(args[i]));
		i++;
	}
	free_strs(args);
}

void	parsing(t_list **lst, char **argv, int argc)
{
	int		iter;

	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			error(lst);
		arg_char(lst, argv);
	}
	if (argc > 2)
	{
		if (argv[1][0] == '\0')
			error(lst);
		verif_number(argc, argv, lst);
		iter = 1;
		while (argv[iter])
		{
			if (ft_strncmp(argv[iter], "", ft_strlen(argv[iter])) == 0)
				error(lst);
			if ((long)ft_atoi(argv[iter]) != ft_atol(argv[iter]))
				error(lst);
			add_to_stack(lst, ft_atoi(argv[iter]));
			iter++;
		}
		verif_double(lst);
	}
}
