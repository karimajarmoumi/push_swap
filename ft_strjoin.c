/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:52:15 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/02/25 14:51:11 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	total_lenth;

	if (!s1 || !s2)
		return (NULL);
	total_lenth = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(total_lenth + 1);
	if (new)
	{
		ft_memcpy(new, s1, ft_strlen(s1));
		ft_memcpy(new + ft_strlen(s1), " ", 1);
		ft_memcpy(new + ft_strlen(s1) + 1, s2, ft_strlen(s2));
	}
	else
	{
		return (NULL);
	}
	new[total_lenth] = '\0';
	return (new);
}
