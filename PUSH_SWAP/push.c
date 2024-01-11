/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:53:49 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/11 12:12:39 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) < 1)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (!*stack_b)
	{
		temp->next = NULL;
		*stack_b = temp;
	}
	else
	{
		temp->next = *stack_b;
		*stack_b = temp;
	}
	ft_putendl_fd("pb", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (!*stack_a)
	{
		temp->next = NULL;
		*stack_a = temp;
	}
	else
	{
		temp->next = *stack_a;
		*stack_a = temp;
	}
	ft_putendl_fd("pa", 1);
}
