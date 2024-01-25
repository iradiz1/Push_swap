/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:52:54 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/22 11:41:40 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	t_list	*temp;
	int		temp_val;

	temp = stack->next;
	temp_val = stack->content;
	stack->content = temp->content;
	temp->content = temp_val;
	temp_val = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_val;
}

void	sa(t_list *stack_a)
{
	if (ft_lstsize(stack_a) < 2)
		return ;
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list *stack_b)
{
	if (ft_lstsize(stack_b) < 2)
		return ;
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
