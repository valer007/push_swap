/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:49:35 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/30 17:39:38 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char *s1, char *s2)
{
    size_t len1 = ft_strlen(s1), len2 = ft_strlen(s2);
    char *new_str = malloc(len1 + len2 + 1);
    size_t i = 0, j = 0;
    
    if (!new_str)
        return NULL;
    if (s1)
    {
        while (s1[i])
        {
            new_str[i] = s1[i];
            i++;
        }
        free(s1);
    }
    while (s2[j])
        new_str[i++] = s2[j++];
    new_str[i] = '\0';
    return new_str;
}

static char *foo(char *str)
{
    char *new_str;
    size_t i = 0, j = 0;

    if (!str)
        return NULL;
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
    return new_str;
}

static char *get_line(char *line)
{
    int i = 0;
    char *new_line;

    if (!line)
        return NULL;
    while (line[i] && line[i] != '\n')
        i++;
    new_line = malloc(sizeof(char) * (i + (line[i] == '\n' ? 2 : 1)));
    if (!new_line)
        return NULL;
    for (int j = 0; j <= i; j++)
        new_line[j] = line[j];
    new_line[i + (line[i] == '\n')] = '\0';
    return new_line;
}

static char *extract_line(char *buffer)
{
    if (!buffer || !buffer[0])
        return NULL;
    return get_line(buffer);
}

char *get_next_line(int fd)
{
    static char *str = NULL;
    char *line;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (!ft_strchr(str, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        str = ft_strjoin(str, buffer);
        if (!str)
            return NULL;
    }
    line = extract_line(str);
    str = foo(str);
    return line;
}
