/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:56:05 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/02/25 13:24:10 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_duplicate(t_stack *list)
{
	t_stack	*p;
	t_stack	*q;

	p = list;
	q = NULL;
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (p->data == q->data)
				ft_exit();
			q = q->next;
		}
		p = p->next;
	}
	return (0);
}
