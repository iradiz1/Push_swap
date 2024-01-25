/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eazy_sorters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:27:39 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/25 11:44:53 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_sorter(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(*stack_a);
	return ;
}

static void	three_sorter(t_list **stack_a)
{
	int	max;

	max = max_node(*stack_a);
	if (max == (*stack_a)->content)
		ra(stack_a);
	if (max == (*stack_a)->next->content)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(*stack_a);
}

static void	four_sorter(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (is_sorted(stack_a) && !ft_lstsize(*stack_b))
		return ;
	min = min_node(*stack_a);
	if (min == (*stack_a)->next->next->next->content)
		while ((*stack_a)->content != min)
			rra(stack_a);
	else if (min != (*stack_a)->content)
		while ((*stack_a)->content != min)
			ra(stack_a);
	pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
	{
		three_sorter(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

static	void	five_sorter(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (is_sorted(stack_a))
		return ;
	min = min_node(*stack_a);
	if (min == (*stack_a)->next->next->next->next->content)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_a) != 3)
	{
		four_sorter(stack_a, stack_b);
		if (is_sorted(stack_a) && !ft_lstsize(*stack_b))
			break ;
	}
}

void	eazy_sorter(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		two_sorter(stack_a);
	if (ft_lstsize(*stack_a) == 3)
		three_sorter(stack_a);
	if (ft_lstsize(*stack_a) == 4)
		four_sorter(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 5)
		five_sorter(stack_a, stack_b);
}
