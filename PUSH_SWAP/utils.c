/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:31:44 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/10 14:10:16 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit (0);
}

int	check_dups(char **res, int arg, int i)
{
	i++;
	while (res[i])
	{
		if (ft_atoi(res[i]) == arg)
			return (1);
		i++;
	}
	return (0);
}

void	free_nodes(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = (head)->next;
		free(head);
		head = NULL;
		head = tmp;
	}
}
