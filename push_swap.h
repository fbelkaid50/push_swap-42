/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:37:57 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 03:10:50 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

int					sorted(t_list *a);
void				initialize_all(t_list *stack_a);
void				five_hundred(t_list **a, t_list **b);
void				put_indx(t_list **stack_a, int index);
void				one_hundred(t_list **a, t_list **b);
int					ft_strlen(char *s);
void				five(t_list **stack_a, t_list **stack_b);
void				rank(t_list *stack_a, int min);
int					repeated_num(t_list *a);
int					ft_atoi(char *str, t_list *p);
char				**ft_split(char *s, char c);
void				three(t_list **a);
void				ft_error_lst(t_list *p, int k);
void				push_swap(t_list **stack_a);
void				ra(t_list **stack_a, int k);
void				rb(t_list **stack_b, int k);
void				rr(t_list **stack_a, t_list **stack_b, int k);
void				rra(t_list **lst, int k);
void				rrb(t_list **lst, int k);
t_list				**sa(t_list **stack_a, int k);
void				sb(t_list **stack_b, int k);
void				ss(t_list *stack_a, t_list *stack_b);
void				pa(t_list **b, t_list **a, int k);
void				pb(t_list **b, t_list **a, int k);
int					ft_strlen(char *s);
int					ft_atoi(char *str, t_list *p);
int					look_indx(t_list *stack_b, int index);
t_list				*listnew(int content);
t_list				*listlast(t_list *lst);
void				list_addback(t_list **lst, t_list *new);
void				list_addfront(t_list **list, t_list *new);
int					listsize(t_list **lst);
void				dividing_stack_a(t_list **stack_a, t_list **stack_b,
						int start, int end);

#endif
