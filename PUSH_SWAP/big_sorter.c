/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:16:44 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/25 12:13:05 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*biggest_node(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if (temp->index > a->index)
			a = temp;
		temp = temp->next;
	}
	return (a);
}

static void	sort_rest(t_list **stack_a)
{
	int		size;
	t_list	*biggest;

	size = ft_lstsize(*stack_a);
	biggest = biggest_node(*stack_a);
	if (biggest->index >= size / 2)
	{
		while (!is_sorted(stack_a))
			rra(stack_a);
	}
	else
	{
		while (!is_sorted(stack_a))
			ra(stack_a);
	}
}

void	push_all_to_b_save_three(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;
	int	max;

	max = max_node(*stack_a);
	size = ft_lstsize(*stack_a);
	pushed = 0;
	while (size > 6 && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	while (size - pushed > 3)
	{
		if ((*stack_a)->content == max)
			ra(stack_a);
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	sort_it(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	make_index(*stack_a, size + 1);
	push_all_to_b_save_three(stack_a, stack_b);
	eazy_sorter(stack_a, stack_b);
	while (*stack_b)
	{
		get_pos(stack_a, stack_b);
		get_targets(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		move_cheapest(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		sort_rest(stack_a);
}
