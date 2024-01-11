/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:54:43 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/11 12:12:34 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last_node;

	temp = *stack;
	last_node = ft_lstlast(*stack);
	while (temp)
	{
		if (temp->next->next == NULL)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	last_node->next = *stack;
	*stack = last_node;
}

void	rra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return ;
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
