/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_and_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:53:44 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/25 12:13:29 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_pos(t_list **stack_a, int target)
{
	int		i;
	t_list	*a;

	a = *stack_a;
	i = 0;
	while (stack_a)
	{
		if (a->index == target)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	get_pos(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	i = 0;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a)
	{
		temp_a->pos = i;
		i++;
		temp_a = temp_a->next;
	}
	i = 0;
	while (temp_b)
	{
		temp_b->pos = i;
		i++;
		temp_b = temp_b->next;
	}
}

void	make_index(t_list *stack_a, int size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->content == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->content > value && ptr->index == 0)
			{
				value = ptr->content;
				highest = ptr;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
