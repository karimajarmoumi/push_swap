/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:34:15 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/02/20 00:10:04 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	word_conter(char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[0] != c) || (s[i] != c && s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

int	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (1);
}

static int	help_function(char *s, char c, char **str, int w_c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (i < w_c)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j])
		{
			if (s[j] == c)
				break ;
			j++;
		}
		str[i] = ft_substr(s, start, j - start);
		(str[i] == NULL) && ft_free(str);
		i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	int		indice;
	char	**str;
	int		w_c;

	str = 0;
	str = NULL;
	if (s)
	{
		w_c = word_conter(s, c);
		str = (char **)malloc((w_c + 1) * sizeof(char *));
		if (str)
		{
			if (w_c == 0)
			{
				str[0] = 0;
				return (str);
			}
			indice = help_function(s, c, str, w_c);
			str[indice] = NULL;
		}
	}
	return (str);
}
