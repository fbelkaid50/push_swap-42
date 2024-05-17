/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:37:37 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 00:16:42 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	repeated_num(t_list *a)
{
	t_list	*ret;

	if (!a)
		ft_error_lst(a, 0);
	ret = a->next;
	while (a)
	{
		ret = a->next;
		while (ret)
		{
			if (a->content == ret->content)
				return (-1);
			ret = ret->next;
		}
		a = a->next;
	}
	return (0);
}

t_list	*hoop(char **av)
{
	int		i;
	int		j;
	char	**s;
	t_list	*new;

	i = 0;
	new = NULL;
	while (av[i])
	{
		s = ft_split(av[i], ' ');
		if (!s)
			ft_error_lst(new, 0);
		j = 0;
		while (s[j])
		{
			list_addback(&new, listnew(ft_atoi(s[j], new)));
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	return (new);
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
	if (repeated_num(stack_a) == -1)
		ft_error_lst(stack_a, 2);
	else if (listsize(&stack_a) == 0)
		ft_error_lst(stack_a, 0);
	push_swap(&stack_a);
}
