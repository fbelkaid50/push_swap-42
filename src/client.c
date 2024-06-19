/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:49:40 by fbelkaid        #+#    #+#             */
/*   Updated: 2024/06/15 12:02:23 by fbelkaid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_signal(unsigned char str, pid_t pid)
{
	int	make_sure;
	int	bits_read;
	int	i;

	make_sure = 0;
	bits_read = 0;
	i = 7;
	while (i >= 0)
	{
		if ((str & (1 << i)) == 0)
			make_sure = kill(pid, SIGUSR1);
		else
			make_sure = kill(pid, SIGUSR2);
		bits_read++;
		if (make_sure == -1)
			exit(0);
		usleep(WAIT_TIME);
		i--;
	}
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_pid(char *av)
{
	size_t	i;
	pid_t	pidd;

	i = 0;
	while (av[i])
	{
		if (!is_digit(av[i++]))
			return (0);
	}
	pidd = ft_atoi(av);
	if (pidd < 1 || pidd > 99998 || kill(pidd, 0) == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (1);
	if (!check_pid(av[1]))
	{
		ft_putstr_fd(RED, 1);
		ft_putstr_fd("Invalid PID, ZYER m3ana !!", 1);
		exit(1);
	}
	while (av[2][i] != '\0')
		send_signal(av[2][i++], ft_atoi(av[1]));
	if (av[2][i] == '\0')
		send_signal(av[2][i], ft_atoi(av[1]));
	return (0);
}
