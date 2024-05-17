/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:38:24 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/10 07:46:44 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **lst, int k)
{
	t_list	*p;
	t_list	*new;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	list_addfront(lst, new);
	if (k)
		write(1, "rra\n", 4);
}

void	rrb(t_list **lst, int k)
{
	t_list	*p;
	t_list	*new;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	list_addfront(lst, new);
	if (k)
		write(1, "rrb\n", 4);
}

void	pa(t_list **a, t_list **b, int k)
{
	t_list	*p;

	if (!b || !*b)
		return ;
	p = (*b);
	(*b) = (*b)->next;
	p->next = NULL;
	list_addfront(a, p);
	if (k)
		write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a, int k)
{
	t_list	*new;

	if (!a || !*a)
		return ;
	new = (*a);
	(*a) = (*a)->next;
	new->next = NULL;
	list_addfront(b, new);
	if (k)
		write(1, "pb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	int	swap;

	if (!stack_a || !stack_b || !stack_a->next || !stack_b->next)
		return ;
	swap = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = swap;
	swap = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = swap;
}
