/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:29:45 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 15:16:39 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap(t_stack **list)
{
	t_stack	*tmp;

	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = *list;
	*list = tmp;
}

void	swap_a_b(t_stack **list, int is_a, int is_ss, t_moves **m)
{
	if (list && (*list) && (*list)->next)
	{
		swap(list);
		if (is_ss == 0)
		{
			if (is_a == 1)
			{
				ft_lstadd_back(m, create_elt_char("sa\n"));
				//write(1, "sa\n", 3);
			}
			else
				ft_lstadd_back(m, create_elt_char("sb\n"));
				//write(1, "sb\n", 3);
		}
	}
}

void	ss(t_stack **a, t_stack **b, t_moves **m)
{
	swap_a_b(a, 1, 1, m);
	swap_a_b(b, 0, 1, m);
	write(1, "ss\n", 3);
}
