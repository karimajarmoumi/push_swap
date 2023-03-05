/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:23:15 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 17:25:40 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack	*remove_first(t_stack **st)
{
	t_stack	*rmv;

	rmv = NULL;
	if (st && *st)
	{
		if ((*st)->next)
		{
			rmv = *st;
			(*st) = (*st)->next;
		}
		else
		{
			rmv = *st;
			*st = NULL;
		}
		rmv->next = NULL;
	}
	return (rmv);
}

void	push_a_b(t_stack **a, t_stack **b)
{
	t_stack	*to_push;

	to_push = remove_first(b);
	if (to_push)
		add_first(a, to_push);
}

void	push(t_stack **a, t_stack **b, int push_to_a, t_moves **m)
{
	if (push_to_a == 1)
	{
		push_a_b(a, b);
		ft_lstadd_back(m, create_elt_char("pa\n"));
		//write(1, "pa\n", 3);
	}
	else
	{
		push_a_b(b, a);
		ft_lstadd_back(m, create_elt_char("pb\n"));
		//write(1, "pb\n", 3);
	}
}
