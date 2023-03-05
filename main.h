/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjarmoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:20:26 by kjarmoum          #+#    #+#             */
/*   Updated: 2023/03/05 15:28:06 by kjarmoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_moves
{
	char			*move;
	struct s_moves	*next;
}					t_moves;

typedef struct s_stack
{
	int				data;
	int				index;
	int				is_ra;
	struct s_stack	*next;
}					t_stack;


void				add_first(t_stack **st, t_stack *add);
char				*ft_strtrim(char const *s1, char const *set);
t_stack				*create_elt(int a);
int					ft_atoi(char *str);
t_stack				*get_list(char **av);
void				ft_exit(void);
int					check_duplicate(t_stack *list);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char *s, char c);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char *s2);
void				*ft_memcpy(void *dst, const void *src, size_t n);
t_stack				*add_elements(char **tab);
int					ft_free(char **str);
void				swap(t_stack **list);
void				swap_a_b(t_stack **list, int is_a, int is_ss, t_moves **m);
void				ss(t_stack **a, t_stack **b, t_moves **m);

void				push_a_b(t_stack **a, t_stack **b);
t_stack				*remove_first(t_stack **st);
void				rotate(t_stack **a);
void				rotate_a_b(t_stack **a, int is_a, int is_rr, t_moves **m);


void				reverse_rotate_a_b(t_stack **a, int is_a, int is_rrr, t_moves **m);
void				reverse_rotate(t_stack **a);
int					size_list(t_stack **list);
int					is_sorted(t_stack *a);

void				sort_5(t_stack **a, t_stack **b, t_moves **m);
void				search_pos_min(t_stack **a, int *min, int *pos_min);
void				min_in_top(t_stack **a, t_moves **m);
void				max_in_top(t_stack **a);
int					*list_to_tab(t_stack *a, int size);
int					*sort_tab(int *tab, int size);
int					min_list(t_stack *list, int *pos);
int					ft_strncmp(char *s1, const char *s2, size_t n);



void				push(t_stack **a, t_stack **b, int push_to_a, t_moves **m);
void				a_to_b(t_stack **a, t_stack **b, t_moves **m);
void				sort_100(t_stack **a, t_stack **b, t_moves **m);
t_moves 			*create_elt_char(const char *str);
void				sort_3(t_stack **a, t_moves **m);
void				rrr(t_stack **a, t_stack **b, t_moves **m);
void				ft_lstadd_back(t_moves **m, t_moves *new);
void				rr(t_stack **a, t_stack **b, t_moves **m);

#endif
