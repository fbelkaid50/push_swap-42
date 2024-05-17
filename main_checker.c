/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:30:15 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 04:40:53 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	repeat_of_numbers(t_list *p)
{
	t_list	*s;

	if (!p)
		ft_error_lst(p, 0);
	s = p->next;
	while (p)
	{
		s = p->next;
		while (s)
		{
			if (p->content == s->content)
				return (-1);
			s = s->next;
		}
		p = p->next;
	}
	return (0);
}

int	check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if ((av[i][j] == '-' && av[i][j + 1]) || (av[i][j] == '+' && av[i][j
				+ 1]))
			j++;
		while (av[i][j])
		{
			if ((av[i][j] == '+' && av[i][j - 1] == ' ' && av[i][j + 1] != ' ')
				|| (av[i][j] == '-' && av[i][j - 1] == ' ' && av[i][j
					+ 1] != ' '))
				j++;
			else if ((av[i][j] == ' ') || (av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

t_list	*hoop(char **av)
{
	int		i;
	int		j;
	char	**s;
	t_list	*p;

	i = 0;
	p = NULL;
	while (av[i])
	{
		s = ft_split(av[i], ' ');
		if (!s)
			ft_error_lst(p, 0);
		j = 0;
		while (s[j])
		{
			list_addback(&p, listnew(ft_atoi(s[j], p)));
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	return (p);
}

int	acses(t_list *stack_a)
{
	int	min;

	if (stack_a)
	{
		min = stack_a->content;
		stack_a = stack_a->next;
	}
	while (stack_a)
	{
		if (min > stack_a->content)
			return (-1);
		min = stack_a->content;
		stack_a = stack_a->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac < 2)
		exit(0);
	if (check(av) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = hoop(av + 1);
	if (repeat_of_numbers(stack_a) == -1)
		ft_error_lst(stack_a, 2);
	else if (listsize(&stack_a) == 0)
		ft_error_lst(stack_a, 2);
	checker(&stack_a);
}
