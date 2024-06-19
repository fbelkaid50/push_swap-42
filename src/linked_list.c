/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:46:30 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/06/16 15:13:14 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr_node = *lst;
	while (curr_node && curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = new;
}

void	free_char(void *c)
{
	free(c);
}

void	ft_free_zmer(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*curr;

	if (!lst || !*lst || !del)
		return ;
	curr = *lst;
	next = curr->next;
	while (curr && next)
	{
		del(curr->content);
		free(curr);
		curr = next;
		next = curr->next;
	}
	del(curr->content);
	free(curr);
	*lst = NULL;
}

int	adding_back(t_list **strptr, char c)
{
	t_list	*new_node;
	char	*mc;

	mc = malloc(sizeof(char));
	if (!mc)
		return (0);
	*mc = c;
	new_node = ft_lstnew(mc);
	if (!new_node)
		return (free(mc), 0);
	ft_lstadd_back(strptr, new_node);
	return (1);
}
