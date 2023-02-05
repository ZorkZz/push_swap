/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:23:29 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/05 17:15:44 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"

void	inter_n_times_no_change(t_list **lst, int n);
void	inter_n_times_change(t_list *lst, int n);
void	add_to_stack(t_list **lst, int i);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack, char c);
void	push(t_list **dst, t_list **src, char c);
void	rotate(t_list **stack, char c);
void	reverse(t_list **stack, char c);
void	free_lst(t_list *lst);
void	parsing(t_list **lst, char **argv, int argc);
void	sort(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack);

#endif