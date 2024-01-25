/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:59:37 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/25 12:27:20 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next == NULL)
		return ;
	if (ft_lstsize(*stack_a) <= 5)
		eazy_sorter(stack_a, stack_b);
	else
		sort_it(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_check_and_create(argc, argv);
	stack_b = NULL;
	if (!is_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	free_nodes(stack_a);
	free_nodes(stack_b);
	return (0);
}
