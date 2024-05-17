/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:54:03 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 15:56:12 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(char *s, unsigned int start, int len)
{
	int				i;
	unsigned int	j;
	char			*p;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (i + start < j && i < len)
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		p[j++] = s[start++];
		i--;
	}
	p[j] = '\0';
	return (p);
}

int	ft_check(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			if (s[i] == c || s[i] == '\0')
				j++;
		}
	}
	return (j);
}

int	ft_hseb(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void	*ft_free_all(char **p, int a)
{
	while (a >= 0)
	{
		free(p[a]);
		a--;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		a;
	int		j;

	a = 0;
	if (!s)
		return (NULL);
	j = ft_check(s, c);
	p = malloc((j + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (a < j)
	{
		while (*s == c && *s)
			s++;
		p[a] = ft_substr(s, 0, ft_hseb(s, c));
		if (!p[a])
			return (ft_free_all(p, a));
		while (*s != c && *s != '\0')
			s++;
		a++;
	}
	p[a] = NULL;
	return (p);
}
