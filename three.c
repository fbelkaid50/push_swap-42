/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:38:24 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/04 18:53:55 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_max(t_list *stack_a, int *min, int *max)
{
	*min = stack_a->content;
	*max = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (*min > stack_a->content)
			*min = stack_a->content;
		if (*max < stack_a->content)
			*max = stack_a->content;
		stack_a = stack_a->next;
	}
}

void	three(t_list **a)
{
	int	min;
	int	max;

	min_max(*a, &min, &max);
	if ((*a)->content != min && (*a)->content != max)
	{
		(*a) = (*a)->next;
		if ((*a)->content == min)
			sa(a, 1);
		else
			rra(a, 1);
	}
	else if ((*a)->content == max)
	{
		(*a) = (*a)->next;
		if ((*a)->content == min)
			ra(a, 1);
		else
			rra(sa(a, 1), 1);
	}
	else if ((*a)->content == min && (*a)->next->content == max)
		ra(sa(a, 1), 1);
}
