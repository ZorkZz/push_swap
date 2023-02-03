/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:31:50 by astachni          #+#    #+#             */
/*   Updated: 2023/02/03 21:40:58 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_strs_split(char const *s, t_list **lst, char c, int index)
{
	int	dst;
	int	first;

	dst = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		first_char = index;
		while (s[index] && s[index] != c)
			index++;
		if (index != first)
		{
			ft_ls
		}
	}
	return (0);
}

void	ft_split_lst(char const *s, char c)
{
	t_list	*lst;

	if (!s)
		return ;
	if (ft_strs_split_lst(s, &lst, c, 0) == -1)
		return ;
}
