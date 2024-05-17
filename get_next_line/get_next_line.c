/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:27:49 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/05/17 04:41:43 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*ft_free(char *buf, char **p)
{
	free(*p);
	*p = NULL;
	free(buf);
	return (NULL);
}

char	*ft_read(int fd, char **p, char *buf)
{
	char	*new;
	int		len;
	int		i;

	new = NULL;
	len = 1;
	while (len > 0)
	{
		len = read(fd, buf, 42);
		if (len == -1)
			return (ft_free(buf, p));
		buf[len] = '\0';
		*p = ft_strjoin(*p, buf);
		i = check_line(*p);
		if (i != -1)
		{
			new = fft_substr(*p, 0, i, 0);
			*p = fft_substr(*p, i + 1, ft_strlen(*p), 1);
			free (buf);
			return (new);
		}
	}
	new = fft_substr(*p, 0, ft_strlen(*p), 0);
	ft_free(buf, p);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*buf;

	if (fd < 0 || 42 <= 0)
		return (NULL);
	buf = malloc(42 + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	return (ft_read(fd, &p, buf));
}
