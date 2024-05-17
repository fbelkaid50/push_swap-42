/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:19:59 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/16 14:47:51 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_a(t_list *a, int start, int end)
{
	while (a)
	{
		if (a->index >= start && a->index <= end)
			return (1);
		a = a->next;
	}
	return (0);
}

void	fdividing_stack_a(t_list **a, t_list **b, int start, int end)
{
	while (check_stack_a(*a, start, end))
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			if (listsize(b) && (*a)->index <= start + (end - start) / 2)
			{
				pb(b, a, 1);
				if ((*a) && ((*a)->index > end || (*a)->index < start))
					rr(a, b, 1);
				else
					rb(b, 1);
			}
			else
				pb(b, a, 1);
		}
		else
			ra(a, 1);
	}
}

void	fonction_help(t_list **a, t_list **b, int size)
{
	while (*b || repeated_num(*a) == -1)
	{
		if (*b && (*b)->index == (*a)->index - 1)
			pa(a, b, 1);
		else if (listlast(*a)->index == (*a)->index - 1)
			rra(a, 1);
		else if (*b && (listlast(*a)->index == size - 1
				|| (*b)->index > listlast(*a)->index))
		{
			pa(a, b, 1);
			if (look_indx(*b, (*a)->index - 1) < listsize(b) / 2)
				rr(a, b, 1);
			else
				ra(a, 1);
		}
		else if (listsize(b) > 1)
		{
			if (look_indx(*b, (*a)->index - 1) < listsize(b) / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
	}
}

void	puch_max(t_list **a, t_list **b)
{
	while (*b)
	{
		if ((*b)->index == listsize(b) - 1)
		{
			pa(a, b, 1);
			return ;
		}
		else
			rb(b, 1);
	}
}

void	five_hundred(t_list **a, t_list **b)
{
	int	size;
	int	i;

	i = 40;
	size = listsize(a);
	initialize_all(*a);
	put_indx(a, size - 1);
	while (*a)
	{
		fdividing_stack_a(a, b, (size / 2) - i, (size / 2) + i);
		i = i + 40;
	}
	puch_max(a, b);
	fonction_help(a, b, size);
}
