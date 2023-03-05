/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:33:35 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 15:16:37 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*p;
	t_stack	*q;

	p = *a;
	while (p->next->next)
		p = p->next;
	q = p->next;
	q->next = *a;
	p->next = NULL;
	(*a) = q;
}

void	reverse_rotate_a_b(t_stack **a, int is_a, int is_rrr, t_moves **m)
{
	if (a && *a && (*a)->next)
	{
		reverse_rotate(a);
		if (is_rrr == 0)
		{
			if (is_a == 1)
				ft_lstadd_back(m, create_elt_char("rra\n"));
				//write(1, "rra\n", 4);
			else
				ft_lstadd_back(m, create_elt_char("rrb\n"));
				//write(1, "rrb\n", 4);
		}
	}
}

void	rrr(t_stack **a, t_stack **b, t_moves **m)
{
	reverse_rotate_a_b(a, 1, 1, m);
	reverse_rotate_a_b(b, 0, 1, m);
	write(1, "rrr\n", 4);
}
