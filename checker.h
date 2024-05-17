/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:30:11 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 04:40:28 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_list	*lstnew(int content);
void	checker(t_list **stack_a);
int		ft_strlen(char *s);
int		check_line(char *str);
char	*ft_substr(char *s, int start, int len, int x);
t_list	*lstlast(t_list *lst);
int		ft_atoi(char *str, t_list *p);
char	**ft_split(char *s, char c);
char	*fft_substr(char *s, int start, int len, int x);
void	lstadd_back(t_list **lst, t_list *new);
void	lstadd_front(t_list **list, t_list *new);
int		lstsize(t_list **lst);
char	*get_next_line(int fd);
char	*ft_free(char *buf, char **p);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		check_line(char *str);
void	ss(t_list *stack_a, t_list *stack_b);

#endif