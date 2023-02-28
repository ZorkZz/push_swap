/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:23:29 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/28 23:55:32 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

t_list	*inter_n_times_no_change(t_list **lst, int n);
t_list	*inter_n_times_change(t_list *lst, int n);
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
void	quick_sort(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack);
int		max_pos(t_list *lst);
int		min_pos(t_list *lst);
int		parsing_error(char c, char d, char e);
void	free_strs(char **strs);
int		ft_lstpos(t_list *lst, int num);
int		take_mean(t_list *stack);
int		mean_verif_max(t_list **stack_a, int mean);
int		mean_verif_min(t_list **stack_a, int mean);
void	radix(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstadd_number(void *number);
void	error(t_list **lst);
void	error_pars(char **strs);
long	ft_atol(char *str);

#endif