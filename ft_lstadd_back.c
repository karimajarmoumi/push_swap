/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:19:25 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 14:41:12 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_lstadd_back(t_moves **m, t_moves *new)
{
	t_moves 	*temp;

	temp = *m;
	if (!temp)
	{
		*m = new;
	}
	else
	{
		if (temp)
			while (temp->next)
				temp = temp->next;
		temp->next = new;
	}
}
