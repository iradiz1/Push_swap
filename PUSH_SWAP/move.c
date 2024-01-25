/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:43:09 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/24 16:31:38 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrr(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

static void	do_rr(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

static void	do_ra(t_list **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(a);
			(*cost_a)++;
		}
	}
}

static void	do_rb(t_list **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(b);
			(*cost_b)++;
		}
	}
}

void	do_move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(a, b, &cost_a, &cost_b);
	do_ra(a, &cost_a);
	do_rb(b, &cost_b);
	pa(a, b);
}
