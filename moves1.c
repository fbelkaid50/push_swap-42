/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:38:24 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/16 14:39:03 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**sa(t_list **stack_a, int k)
{
	int		temp;
	t_list	*list;

	if (!(*stack_a) || !(*stack_a)->next)
		return (NULL);
	list = *stack_a;
	temp = list->content;
	list->content = list->next->content;
	list->next->content = temp;
	if (k)
		write(1, "sa\n", 3);
	return (stack_a);
}

void	sb(t_list **stack_b, int k)
{
	int	temp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->content;
	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	if (k)
		write(1, "sb\n", 3);
}

void	ra(t_list **lst, int k)
{
	t_list	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	list_addback(lst, p);
	if (k)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int k)
{
	t_list	*list;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	list = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	list->next = NULL;
	list_addback(stack_b, list);
	if (k)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int k)
{
	t_list	*list;

	if (!(*stack_a) || !(*stack_b) || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	list = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	list->next = NULL;
	list_addback(stack_a, list);
	list = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	list->next = NULL;
	list_addback(stack_b, list);
	if (k)
		write(1, "rr\n", 3);
}
