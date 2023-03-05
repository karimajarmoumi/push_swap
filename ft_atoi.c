/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:55:42 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/02/25 13:24:17 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_atoi(char *str)
{
	int				i;
	unsigned long	result;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		(str[i] == '-') && (sign *= -1);
		i++;
	}
	if (str[i] == '\0')
		ft_exit();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = str[i++] + result * 10 - '0';
		if ((result > 2147483647 && sign == 1) || (result > 2147483648
				&& sign == -1))
			ft_exit();
	}
	if (str[i] != '\0')
		ft_exit();
	return (result * sign);
}
