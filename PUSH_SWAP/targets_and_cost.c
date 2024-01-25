/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets_and_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:33:36 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/25 12:19:26 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

t_list	*smallest_node(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if (temp->index < a->index)
			a = temp;
		temp = temp->next;
	}
	return (a);
}

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;
	int		size_a;
	int		size_b;

	temp_b = *stack_b;
	temp_a = *stack_a;
	size_a = ft_lstsize(*stack_a) + 1;
	size_b = ft_lstsize(*stack_b) + 1;
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2 - 1)
			temp_b->cost_b = temp_b->pos - size_b + 1;
		temp_b->cost_a = target_pos(&temp_a, temp_b->target);
		if (temp_b->cost_a > size_a / 2)
			temp_b->cost_a = temp_b->cost_a - size_a + 1;
		temp_b = temp_b->next;
	}
}

void	get_targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;
	t_list	*smallest;

	temp_a = *stack_a;
	temp_b = *stack_b;
	smallest = smallest_node(temp_a);
	while (temp_b)
	{
		while (temp_a)
		{
			if (temp_b->index < temp_a->index && temp_b->target > temp_a->index)
				temp_b->target = temp_a->index;
			temp_a = temp_a->next;
		}
		if (temp_b->target == INT_MAX)
			temp_b->target = smallest->index;
		temp_a = *stack_a;
		temp_b = temp_b->next;
	}
}

void	move_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (get_abs(temp->cost_a) + get_abs(temp->cost_b) < get_abs(cheapest))
		{
			cheapest = get_abs(temp->cost_a) + get_abs(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
