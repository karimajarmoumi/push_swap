/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:10:19 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 15:01:17 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	search_pos_min(t_stack **a, int *min, int *pos_min)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	*min = (*a)->data;
	while (tmp)
	{
		if (*min > tmp->data)
		{
			*min = tmp->data;
			*pos_min = i;
		}
		i++;
		tmp = tmp->next;
	}
}

void	sort_5(t_stack **a, t_stack **b, t_moves **m)
{
	if (is_sorted(*a) == 0)
	{
		min_in_top(a, m);
		push(a, b, 0, m);
		min_in_top(a, m);
		push(a, b, 0, m);
		sort_3(a, m);
		push(a, b, 1, m);
		push(a, b, 1, m);
	}
}

void	min_in_top(t_stack **a, t_moves **m)
{
	int	min;
	int	pos_min;

	min = 0;
	pos_min = 0;
	search_pos_min(a, &min, &pos_min);
	if (pos_min <= 2)
	{
		while ((*a)->data != min)
			rotate_a_b(a, 1, 0, m);
	}
	else
		while ((*a)->data != min)
			reverse_rotate_a_b(a, 1, 0, m);
}
