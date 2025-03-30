/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:49:35 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/30 21:29:44 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	i = 0;
	j = 0;
	if (!new_str)
		return (NULL);
	if (s1)
	{
		while (s1[i++])
			new_str[i] = s1[i];
		free(s1);
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

static char	*foo(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	new_str = malloc(ft_strlen(str) - i);
	if (!new_str)
		return (free(str), NULL);
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

static char	*get_line(char *line)
{
	int		i;
	char	*new_line;
	int		j;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		new_line = malloc(sizeof(char) * (i + 2));
	else
		new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	j = 0;
	while (j++ <= i)
	{
		new_line[j] = line[j];
	}
	if (line[i] == '\n')
		new_line[i + 1] = '\0';
	else
		new_line[i] = '\0';
	return (new_line);
}

static char	*extract_line(char *buffer)
{
	if (!buffer || !buffer[0])
		return (NULL);
	return (get_line(buffer));
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	line = extract_line(str);
	str = foo(str);
	return (line);
}
