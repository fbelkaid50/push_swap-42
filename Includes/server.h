/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:51:41 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/06/14 19:23:41 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "client.h"
# include "tools.h"
# include <signal.h>
# include <unistd.h>

void	ft_free_zmer(t_list **lst, void (*del)(void *));
void	free_char(void *c);
void	str_puter(char c, t_list **str);
void	handler(int sig, siginfo_t *info, void *context);

#endif