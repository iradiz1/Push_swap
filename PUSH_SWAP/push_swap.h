/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:35:18 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/25 12:35:26 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		ft_check_digit(char **argv);
t_list	*create_nodes(t_list *head, int data);
void	free_nodes(t_list *head);
void	ft_error(char *msg);
int		check_dups(char **res, int arg, int i);
t_list	*ft_check_and_create(int argc, char **argv);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	eazy_sorter(t_list **stack_a, t_list **stack_b);
int		max_node(t_list *stack);
int		min_node(t_list *stack);
int		is_sorted(t_list **stack);
void	sort_it(t_list **stack_a, t_list **stack_b);
void	get_targets(t_list **stack_a, t_list **stack_b);
void	make_index(t_list *stack_a, int size);
void	get_pos(t_list **stack_a, t_list **stack_b);
void	get_cost(t_list **stack_a, t_list **stack_b);
void	move_cheapest(t_list **stack_a, t_list **stack_b);
void	do_move(t_list **a, t_list **b, int cost_a, int cost_b);
t_list	*smallest_node(t_list *a);
t_list	*biggest_node(t_list *a);
int		target_pos(t_list **stack_a, int target);

#endif