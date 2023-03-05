/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:19:22 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/02/25 14:45:53 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack	*add_back(t_stack *l, t_stack *add)
{
	t_stack	*tmp;

	tmp = l;
	if (l == NULL)
		return (add);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
	return (l);
}

t_stack	*add_elements(char **tab)
{
	t_stack	*elt;
	t_stack	*list;
	int		i;

	i = 0;
	list = NULL;
	elt = NULL;
	while (tab[i])
	{
		elt = create_elt(ft_atoi(tab[i]));
		list = add_back(list, elt);
		i++;
	}
	return (list);
}

t_stack	*get_list(char **av)
{
	int		i;
	char	*total;
	char	*fr;
	char	**tab;
	t_stack	*list;

	i = 1;
	total = ft_strdup("");
	while (av[i])
	{
		fr = ft_strtrim(av[i], " ");
		if (ft_strlen(fr) == 0)
			ft_exit();
		free(fr);
		fr = total;
		total = ft_strjoin(total, av[i]);
		free(fr);
		i++;
	}
	tab = ft_split(total, ' ');
	list = add_elements(tab);
	free(total);
	ft_free(tab);
	check_duplicate(list);
	return (list);
}
