/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:42:31 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 20:41:13 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	a_to_b(t_stack **a, t_stack **b, t_moves **m)
{
	int		size;
	int 	*arr;
	int *array;
	int mid;

	size = size_list(a);
	arr = list_to_tab(*a, size);
	array = sort_tab(arr, size);
	mid = array[size / 2];
	while (size > 3)
	{
		push(a, b, 0, m);
		if (mid > (*b)->data)
			rotate_a_b(b, 0, 0, m);
		size--;
	}
}

void	index_data(t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *b;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void min_mv(int *tab, int size, int *min_mov, int *pos_min)
{
	int i;

	i = 0;
	*pos_min = i;
	*min_mov = tab[i];
	while (i < size)
	{
		if (*min_mov > tab[i])
		{
			*min_mov = tab[i];
			*pos_min = i;
		}
		i++;
	}
}

t_stack	*get_end(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a);
}

int min_list(t_stack *list, int *pos)
{
	int	min;
	int	i;

	i = 0;
	min = list->data;
	while (list)
	{
		if (min > list->data)
		{
			min = list->data;
			(*pos) = i;
		}
		++i;
		list = list->next;
	}
	return (min);
}

int max_list(t_stack *list, int *p)
{
	int max;
	int i;

	i = 0;
	max = list->data;
	while (list)
	{
		if (max < list->data)
		{
			max = list->data;
			*p = i;
		}
		i++;
		list = list->next;
	}
	return (max);
}

int	*count_move_in_b(t_stack **a, t_stack **b, int size_a, int size_b)
{
	int		*number_move;
	t_stack	*a_a;
	t_stack	*b_b;
	int min_lst;
	int max_lst;
	int pos_mx;
	int pos_mn;


	number_move = malloc(sizeof(int) * size_b);
	if (number_move)
	{

		b_b = *b;
		while (b_b)
		{
			if (size_b - b_b->index > (size_b / 2))
				number_move[b_b->index] = b_b->index;
			else
				number_move[b_b->index] = size_b - b_b->index;

			a_a = *a;
			pos_mx = 0;
			min_lst = min_list(*a, &pos_mn);
			max_lst = max_list(*a, &pos_mx);
			if (b_b->data > max_lst || b_b->data < min_lst)
			{
				if (pos_mx >= size_a / 2)
				{
					b_b->is_ra = 0;
					number_move[b_b->index] += size_a - pos_mx - 1;
				}
				else
				{
					b_b->is_ra = 1;
					number_move[b_b->index] += pos_mx + 1;
				}
			}
			else
			{
				while (a_a->next)
				{
					if (b_b->data > a_a->data && b_b->data < a_a->next->data)
					{
						if (a_a->next->index <= size_list(a) / 2)
						{
							b_b->is_ra = 1;
							number_move[b_b->index] += a_a->next->index;
						}
						else
						{
							b_b->is_ra = 0;
							number_move[b_b->index] +=  size_list(a) - a_a->next->index;
						}
						break;
					}
					a_a = a_a->next;
				}
			}
			b_b = b_b->next;
		}

		return (number_move);
	}
	return (0);
}


void	sort_100(t_stack **a, t_stack **b, t_moves **m)
{
	int i;
	int min_mov;
	int pos_min;
	int rot;
	int *tab_moves;
	int *fr;


	t_stack *tmp;


	i = 0;
	tmp = 0;
	rot = 0;
	if (is_sorted(*a) == 0)
	{
		a_to_b(a, b, m);
		sort_3(a, m);
		index_data(a);
		index_data(b);

		tab_moves = count_move_in_b(a, b, size_list(a), size_list(b));
		min_mv(tab_moves, size_list(b), &min_mov, &pos_min);

		int pos_m;
		while (*b)
		{
			pos_m  = pos_min;
			while ((*b)->index != pos_min)
			{
				if (pos_m > size_list(a) / 2)
					reverse_rotate_a_b(b, 0, 0, m);
				else
					rotate_a_b(b, 0, 0, m);
				index_data(b);
				tab_moves = count_move_in_b(a, b, size_list(a), size_list(b));
				min_mv(tab_moves, size_list(b), &min_mov, &pos_min);
			}
			while (tab_moves[pos_min] > 0)
			{
				if ((*b)->is_ra == 0)
					reverse_rotate_a_b(a, 1, 0, m);
				else
					rotate_a_b(a, 1, 0, m);
				tab_moves[pos_min]--;
				index_data(a);
			}
			if (tab_moves[pos_min] == 0)
			{
				push(a, b, 1, m);
				index_data(a);
				index_data(b);
			}
			fr = tab_moves;
			free(fr);
			tab_moves = count_move_in_b(a, b, size_list(a), size_list(b));
			min_mv(tab_moves, size_list(b), &min_mov, &pos_min);
		}
	}

}