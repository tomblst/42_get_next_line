/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbellest <tbellest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:21:18 by tbellest          #+#    #+#             */
/*   Updated: 2024/12/02 11:31:59 by tbellest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#define MAX_FD 1024

static char	*ft_substr(char const *s, unsigned int start, size_t len);

static char	*big_line(char *buffer, char *stock, char *temp, int fd)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!stock)
			stock = ft_strdup("");
		temp = stock;
		stock = ft_strjoin(temp, buffer);
		if (!stock)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(stock, '\n'))
			break ;
	}
	free(buffer);
	return (buffer = NULL, stock);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stock[MAX_FD];
	int			i;
	char		*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (free(stock[fd]), buffer = NULL, stock[fd] = NULL, NULL);
	}
	if (!buffer)
		return (NULL);
	temp = NULL;
	stock[fd] = big_line(buffer, stock[fd], temp, fd);
	if (!stock[fd] || *stock[fd] == '\0')
		return (free(stock[fd]), stock[fd] = NULL, NULL);
	i = 0;
	while (stock[fd][i] != '\n' && stock[fd][i] != '\0')
		i++;
	line = ft_substr(stock[fd], 0, i + 1);
	temp = stock[fd];
	stock[fd] = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	return (free(temp), line);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
