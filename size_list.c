/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:36:28 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/02/25 13:37:26 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	size_list(t_stack **list)
{
	int		c;
	t_stack	*tmp;

	c = 0;
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}
