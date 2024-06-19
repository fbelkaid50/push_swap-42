/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:18:38 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/06/16 19:42:51 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

pid_t	g_pid;

void	str_puter(char c, t_list **str)
{
	t_list	*tmp;

	if (c)
	{
		if (!adding_back(str, c))
			ft_free_zmer(str, free_char);
	}
	else
	{
		tmp = *str;
		while (*str && *(char *)(*str)->content)
		{
			ft_putchar_fd(*(char *)(*str)->content, 1);
			(*str) = (*str)->next;
		}
		ft_free_zmer(&tmp, free_char);
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static t_list	*str;
	static int		i;
	unsigned char	c;

	(void)context;
	if (info->si_pid != g_pid)
	{
		g_pid = info->si_pid;
		if (str)
		{
			ft_free_zmer(&str, free_char);
			i = 0;
			c = 0;
		}
	}
	if (sig == SIGUSR1)
		c = c << 1;
	if (sig == SIGUSR2)
		c = (c << 1) | 1;
	i++;
	if (i == 8)
	{
		str_puter(c, &str);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_pid = getpid();
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	ft_putnbr_fd(g_pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
