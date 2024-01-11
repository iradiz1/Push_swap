/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:48:56 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/08 11:03:47 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int data)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(head));
	if (!head)
		return (0);
	head->content = data;
	head->next = NULL;
	return (head);
}
