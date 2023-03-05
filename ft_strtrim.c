/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:09:01 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/02/22 18:05:49 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	is_ok(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ch;

	i = 0;
	start = 0;
	ch = NULL;
	if (s1 && set)
	{
		while (s1[i] && is_ok(s1[i], set))
			i++;
		start = i;
		end = ft_strlen(s1) - 1;
		while (end >= start && is_ok(s1[end], set))
			end--;
		ch = ft_substr(s1, start, end - start + 1);
	}
	return (ch);
}
