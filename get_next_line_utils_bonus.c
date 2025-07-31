/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbellest <tbellest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:44:19 by tbellest          #+#    #+#             */
/*   Updated: 2024/12/02 11:31:49 by tbellest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*array;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	array = malloc((len1 + len2 + 1) * sizeof(char));
	if (!array)
		return (NULL);
	ft_memcpy(array, s1, len1);
	ft_memcpy(array + len1, s2, len2);
	array[len1 + len2] = '\0';
	return (array);
}

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(str) + 1;
	copy = malloc(size);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, size);
	return (copy);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*desttt;
	unsigned char	*srccc;
	size_t			i;

	srccc = (unsigned char *)src;
	desttt = (unsigned char *)dest;
	if (!srccc && !desttt)
		return (NULL);
	i = 0;
	while (i < n)
	{
		desttt[i] = srccc[i];
		i++;
	}
	return (dest);
}
