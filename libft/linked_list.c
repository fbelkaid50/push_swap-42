/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:54:17 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 15:56:22 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	list_addback(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->next = NULL;
}

t_list	*listnew(int content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}

void	list_addfront(t_list **lst, t_list *new)
{
	if (!lst)
		*lst = new;
	new->next = (*lst);
	(*lst) = new;
}

int	listsize(t_list **lst)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_list	*listlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
