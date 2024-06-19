/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:54:03 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/06/14 19:13:44 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "tools.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	send_signal(unsigned char str, pid_t pid);
int		check_pid(char *av);
void	ft_putnbr_fd(int n, int fd);

#endif