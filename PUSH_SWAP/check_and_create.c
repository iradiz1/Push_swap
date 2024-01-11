/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:57:34 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/11 11:58:05 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*create_nodes(t_list *head, int data)
{
	static int	i = 0;
	t_list		*temp;
	t_list		*new;

	new = ft_lstnew(data);
	if (!new)
		ft_error("Error");
	if (i < 1)
	{
		head = new;
		i++;
		return (head);
	}
	temp = ft_lstlast(head);
	if (i > 0)
		temp->next = new;
	return (head);
}

static void	ft_check_digit(char **argv)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (argv[a])
	{
		while (argv[a] && argv[a][i])
		{
			if (i == 0)
			{
				if (argv[a][0] == '-' || argv[a][0] == '+')
					i++;
			}
			if (!ft_isdigit(argv[a][i]))
				ft_error("Error");
			i++;
		}
		i = 0;
		a++;
	}
}

t_list	*ft_check_and_create(int argc, char **argv)
{
	static char	**res;
	t_list		*head;
	int			i;

	i = 0;
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		if (!res)
			ft_error("Error");
	}
	else
		res = ++argv;
	ft_check_digit(res);
	while (res[i])
	{
		head = create_nodes(head, ft_atoi(res[i]));
		if (!head)
			ft_error("Error");
		if (check_dups(res, ft_atoi(res[i]), i))
			ft_error("Error");
		i++;
	}
	return (head);
}
