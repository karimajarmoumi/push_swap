/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:12:12 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/04 15:24:59 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	three_elements(t_stack **a, t_moves **m, t_stack *midl, t_stack *end)
{
	t_stack *top;

	top = *a;
	if (is_sorted(*a) == 0)
	{
		if (top->data > midl->data && end->data > top->data)
			swap_a_b(a, 1, 0, m);
		else if (top->data > midl->data && midl->data > end->data)
		{
			rotate_a_b(a, 1, 0, m);
			swap_a_b(a, 1, 0, m);
		}
		else if (top->data > end->data && end->data > midl->data)
			rotate_a_b(a, 1, 0, m);
		else if (midl->data > top->data && end->data > top->data)
		{
			swap_a_b(a, 1, 0, m);
			rotate_a_b(a, 1, 0, m);
		}
		else
			reverse_rotate_a_b(a, 1, 0, m);
	}
}

void	sort_3(t_stack **a, t_moves **m)
{

	t_stack	*midl;
	t_stack	*end;


	midl = (*a)->next;
	end = midl->next;
	three_elements(a, m, midl, end);
}
