/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:28:25 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/16 15:54:07 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*fft_substr(char *s, int start, int len, int x)
{
	char	*p;
	int		i;

	if (start > len)
		return (NULL);
	p = malloc((len - start + 2) * sizeof(char));
	if (!p)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (start <= len)
		p[i++] = s[start++];
	if (x == 1)
		free(s);
	p[i] = '\0';
	if (p[0] == '\0')
	{
		free(p);
		return (NULL);
	}
	return (p);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
	{
		free (s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	free(s1);
	return (p);
}
