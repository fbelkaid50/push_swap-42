/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:53:56 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 15:56:00 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_lst(t_list *p, int k)
{
	t_list	*s;

	if (k == 1)
		write(2, "max or min de int !\n", 20);
	else if (k == 2)
		write(2, "duplicate numbers !\n", 20);
	else
		write(2, "Error\n", 6);
	if (!p)
		exit(5);
	while (p)
	{
		s = p;
		p = p->next;
		free(s);
	}
	exit(1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, t_list *p)
{
	int		x;
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	x = 1;
	if (str[i] == '-')
	{
		x = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	if (nbr * x > 2147483647 || nbr * x < -2147483648)
		ft_error_lst(p, 1);
	return (nbr * x);
}
