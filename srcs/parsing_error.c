/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:02:52 by astachni          #+#    #+#             */
/*   Updated: 2023/02/16 15:38:53 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	parsing_error(char c, char d, char e)
{
	if ((c < '0' || c > '9') && c != '-')
	{
		ft_putendl_fd("error", 2);
		exit(1);
	}
	else if (c == '-' && (!d || ft_isdigit(d) == 0))
	{
		ft_putendl_fd("error", 2);
		exit(1);
	}
	else if (c == '-' && ft_isdigit(e) != 0)
	{
		ft_putendl_fd("error", 2);
		exit(1);
	}
}