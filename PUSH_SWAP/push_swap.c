/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:59:37 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/11 12:20:52 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_check_and_create(argc, argv);
	stack_b = NULL;
	 pb(&stack_a, &stack_b);
	 pb(&stack_a, &stack_b);
	//  pb(&stack_a, &stack_b);
	//  pa(&stack_a, &stack_b);
	//  rr(&stack_a, &stack_b);
	 ra(&stack_a);
	 rb(&stack_b);
	//  sa(stack_a);
	//  sb(stack_b);
	//  ss(stack_a, stack_b);
	 rra(&stack_a);
	 rrb(&stack_b);
	 rrr(&stack_a, &stack_b);
	// while (stack_a)
	// {
	// 	printf("stack_a: %d\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b)
	// {
	// 	printf("stack_b: %d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// }
	free_nodes(stack_a);
	return (0);
}
