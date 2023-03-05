/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:32:40 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 15:16:38 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*p;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	p = (*a)->next;
	tmp->next = (*a);
	(*a)->next = NULL;
	(*a) = p;
}

void	rotate_a_b(t_stack **a, int is_a, int is_rr, t_moves **m)
{
	if (a && *a && (*a)->next)
	{
		rotate(a);
		if (is_rr == 0)
		{
			if (is_a == 1)
				ft_lstadd_back(m, create_elt_char("ra\n"));
				//write(1, "ra\n", 3);
			else
				ft_lstadd_back(m, create_elt_char("rb\n"));
				// write(1, "rb\n", 3);
		}
	}
}

void	rr(t_stack **a, t_stack **b, t_moves **m)
{
	rotate_a_b(a, 1, 1, m);
	rotate_a_b(b, 0, 1, m);
	write(1, "rr\n", 3);
}
