/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:38:44 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 03:18:31 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	t_list	*new;

	if (!(*stack_a) || !(*stack_b) || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	p = (*stack_a);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	list_addfront(stack_a, new);
	p = (*stack_b);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	list_addfront(stack_b, new);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	help(char *s, t_list **stack_a, t_list **stack_b)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		pa(stack_a, stack_b, 0);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		pb(stack_b, stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ra(stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rb(stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rr(stack_a, stack_b, 0);
	else if (s[2] == '\n')
		error_exit();
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrb(stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rrr(stack_a, stack_b);
	else
		error_exit();
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

void	checker(t_list **stack_a)
{
	t_list	*stack_b;
	char	*str;

	stack_b = NULL;
	str = "";
	while (str)
	{
		str = get_next_line(0);
		if (!str || !str[0])
			break ;
		if (str[0] == '\n' || str[1] == '\n')
			error_exit();
		if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
			sa(stack_a, 0);
		else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
			sb(&stack_b, 0);
		else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
			ss(*stack_a, stack_b);
		else
			help(str, stack_a, &stack_b);
	}
	if (sorted(*stack_a) == 0)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}
