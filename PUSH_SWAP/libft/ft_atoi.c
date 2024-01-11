/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:29:23 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/05 12:11:18 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long		i;
	long		m;
	long long	p;

	i = 0;
	m = 1;
	p = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		p = p * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] < 48 && str[i] > 57)
		return (0);
	return (p * m);
}
