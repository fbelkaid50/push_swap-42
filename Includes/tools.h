/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:55:56 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/06/16 13:01:31 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# define WAIT_TIME 100

# include "linked_list.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define GREEN "\033[1;32m"
# define COLOR_RESET "\033[0m"

int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif