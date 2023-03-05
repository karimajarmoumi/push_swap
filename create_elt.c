/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:16:38 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 19:50:50 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack	*create_elt(int a)
{
	t_stack	*elt;

	elt = malloc(sizeof(t_stack));
	elt->data = a;
	elt->next = NULL;
	return (elt);
}

t_moves *create_elt_char(const char *str)
{
	t_moves	*new;

	new = malloc(sizeof(t_stack));
	new->move = ft_strdup(str);
	new->next = NULL;
	return (new);
}

























