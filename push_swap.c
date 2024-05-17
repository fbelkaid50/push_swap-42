/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:38:24 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 03:11:28 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_indx(t_list **stack_a, int index)
{
	t_list	*temp;
	int		min;

	while (index >= 0)
	{
		temp = *stack_a;
		while (temp)
		{
			if (temp->index == -1)
			{
				min = temp->content;
				break ;
			}
			temp = temp->next;
		}
		temp = *stack_a;
		while (temp)
		{
			if (min > temp->content && temp->index == -1)
				min = temp->content;
			temp = temp->next;
		}
		rank(*stack_a, min);
		index--;
	}
}

int	sorted(t_list *a)
{
	int	min;

	if (a)
	{
		min = a->content;
		a = a->next;
	}
	while (a)
	{
		if (min > a->content)
			return (-1);
		min = a->content;
		a = a->next;
	}
	return (0);
}

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = 0;
	if (listsize(stack_a) == 1 || sorted(*stack_a) == 0)
		exit(0);
	else if (listsize(stack_a) == 2)
		sa(stack_a, 1);
	else if (listsize(stack_a) == 3)
		three(stack_a);
	else if (listsize(stack_a) == 4 || listsize(stack_a) == 5)
		five(stack_a, &stack_b);
	else if (listsize(stack_a) <= 100)
		one_hundred(stack_a, &stack_b);
	else
		five_hundred(stack_a, &stack_b);
}
