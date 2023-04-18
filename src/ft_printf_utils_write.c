/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_write.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:55:53 by flauer            #+#    #+#             */
/*   Updated: 2023/04/18 16:29:25 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

bool	f_putst(int fd, const void *buf, t_printf *st)
{
	return (f_write(fd, buf + st->cws, st->i - st->cws, &st->bytes));
}

bool	f_write(int fd, const void *buf, size_t nbyte, int *bytes_written)
{
	int	n;

	n = write(fd, buf, nbyte);
	if (n >= 0)
	{
		*bytes_written += n;
		return (true);
	}
	return (false);
}

bool	f_putchar_fd(char c, int fd, int *bytes_written)
{
	return (f_write(fd, &c, 1, bytes_written));
}

bool	f_putstr_fd(int fd, char *s, int *bytes_written)
{
	int	len;

	if (!s)
		return (f_putstr_fd(fd, "(null)", bytes_written));
	len = ft_strlen(s);
	return (f_write(fd, s, len, bytes_written));
}
