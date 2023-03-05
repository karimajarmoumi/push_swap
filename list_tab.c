/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:21:25 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 20:32:58 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	*list_to_tab(t_stack *a, int size)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tab = malloc(sizeof(int) * (size));
	tmp = a;
	i = 0;
	if (tab)
	{
		while (tmp)
		{
			tab[i] = tmp->data;
			tmp = tmp->next;
			i++;
		}
	}
	return (tab);
}

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = tab[0];
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
