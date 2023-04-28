/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:25:27 by flauer            #+#    #+#             */
/*   Updated: 2023/04/28 11:32:06 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*nl_from_state_buf(char *buf, int end)
{
	char	*result;
	size_t	len;

	result = ft_substr(buf, 0, end + 1);
	if (!result)
		return (NULL);
	len = ft_strlen(buf + end + 1);
	ft_memmove(buf, buf + end + 1, len);
	ft_bzero(buf + len, BUFFER_SIZE - len);
	return (result);
}

static char	*nl_from_read_buf(char *result, char *buf)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	if (!result)
		return (NULL);
	len = ft_strlen(result);
	while (i < len && result[i])
	{
		if (result[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	ft_memmove(buf, result + i, len - i);
	ft_bzero(buf + len - i, BUFFER_SIZE - (len - i));
	res = ft_substr(result, 0, i);
	free (result);
	result = NULL;
	return (res);
}

static int	check_buf(const char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (i < BUFFER_SIZE && buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static bool	read_recursive(int fd, char **result, size_t *result_size)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0 || (bytes_read == 0 && *result_size == 0))
		return (false);
	else if (bytes_read == 0 || check_buf(buffer))
	{
		*result = malloc(sizeof(**result) * (*result_size + bytes_read + 1));
		if (!*result)
			return (false);
		(*result)[*result_size + bytes_read] = '\0';
		if (bytes_read)
			ft_memmove(*result + *result_size, buffer, bytes_read);
		return (true);
	}
	*result_size += bytes_read;
	if (!read_recursive(fd, result, result_size))
		return (false);
	ft_memmove(*result + *result_size - bytes_read, buffer, bytes_read);
	*result_size = *result_size - bytes_read;
	return (true);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	size_t		result_size;
	size_t		i;
	char		*result;

	i = 0;
	result_size = 0;
	result = NULL;
	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	while (buf[fd][i] && buf[fd][i] != '\n')
		i++;
	if (buf[fd][i] == '\n')
		return (nl_from_state_buf(buf[fd], i));
	result_size = i;
	if (!read_recursive(fd, &result, &result_size))
	{
		ft_bzero(buf[fd], BUFFER_SIZE + 1);
		return (NULL);
	}
	ft_memmove(result, buf[fd], i);
	return (nl_from_read_buf(result, buf[fd]));
}
