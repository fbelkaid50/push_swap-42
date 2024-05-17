/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:38:24 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/16 14:48:09 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_min(t_list *stack_a, int min)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content == min)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	min_five(t_list *stack_a, int *min)
{
	t_list	*a;
	int		index;

	a = stack_a;
	*min = a->content;
	a = a->next;
	while (a)
	{
		if (*min > a->content)
			*min = a->content;
		a = a->next;
	}
	index = index_min(stack_a, *min);
	return (index);
}

void	five(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	min;

	while (listsize(stack_a) > 3)
	{
		index = min_five(*stack_a, &min);
		if (index >= (5 / 2))
		{
			while ((*stack_a)->content != min)
				rra(stack_a, 1);
			pb(stack_b, stack_a, 1);
		}
		else if (index < (5 / 2))
		{
			while ((*stack_a)->content != min)
				ra(stack_a, 1);
			pb(stack_b, stack_a, 1);
		}
	}
	three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
