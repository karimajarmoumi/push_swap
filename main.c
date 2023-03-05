/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:15:12 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 17:29:24 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	find_min(t_stack **a, t_moves **m)
{
	int	min;
	int	pos;

	min = min_list(*a, &pos);
	while (*a && (*a)->data != min)
	{
		if (pos >= size_list(a)/2)
			reverse_rotate_a_b(a, 1, 0, m);
		else
			rotate_a_b(a, 1, 0, m);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_moves *m;
	t_moves *tmp;
	int		size;

	a = NULL;
	b = NULL;
	m = NULL;
	size = 0;
	if (argc == 1)
		return (0);
	else
	{
		a = get_list(argv);
		size = size_list(&a);

		if (size == 3)
			sort_3(&a, &m);
		else if (size == 5)
			sort_5(&a, &b, &m);
		else{
			sort_100(&a, &b, &m);
			find_min(&a, &m);
		}

		// while(tmp)
		// {
		// 	printf("%s",tmp->move);
		// 	tmp = tmp->next;
		// }
		// 	tmp = m;

		// t_stack *tmp;
		// tmp = a;
		// while(tmp)
		// {
		// 	printf("%d\n",tmp->data);
		// 	tmp = tmp->next;
		// }
		tmp = m;
		while (tmp && tmp->next)
		{
			if ((ft_strncmp(tmp->move, "ra\n", 3) == 0 &&  ft_strncmp(tmp->next->move, "rb\n", 3) == 0)
				|| (ft_strncmp(tmp->move, "rb\n", 3) == 0 &&  ft_strncmp(tmp->next->move, "ra\n", 3) == 0))
			{
				printf("rr\n");
				tmp = tmp->next;
			}
			else if ((ft_strncmp(tmp->move, "rra\n", 4) == 0 &&  ft_strncmp(tmp->next->move, "rrb\n", 4) == 0)||
						(ft_strncmp(tmp->move, "rrb\n", 4) == 0 &&  ft_strncmp(tmp->next->move, "rra\n", 4) == 0))
			{
				printf("rrr\n");
				tmp = tmp->next;
			}
			else
				printf("%s", tmp->move);
			tmp = tmp->next;
		}
		if (tmp)
			printf("%s", tmp->move);


		// if (is_sorted(a) == 1)
		// 	printf("sorteed\n");

		//system("leaks a.out");
	}
}
