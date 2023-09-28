/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:17:53 by flauer            #+#    #+#             */
/*   Updated: 2023/09/28 12:11:44 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

bool	handle_flag(char *curr_pos, t_printf *st)
{
	bool	ret;

	++(st->i);
	ret = true;
	if (curr_pos[st->i] == 'c')
		ret &= f_putchar_fd(va_arg(st->args, int), 1, &st->bytes);
	else if (curr_pos[st->i] == 's')
		ret &= f_putstr_fd(1, va_arg(st->args, char *), &st->bytes);
	else if (curr_pos[st->i] == 'p')
		ret &= f_putptr(va_arg(st->args, void *), 1, &st->bytes);
	else if (curr_pos[st->i] == 'd' || curr_pos[st->i] == 'i')
		ret &= f_putnbr_fd(va_arg(st->args, int), 1, &st->bytes);
	else if (curr_pos[st->i] == 'u')
		ret &= f_putunbr(va_arg(st->args, unsigned int), 1, &st->bytes);
	else if (curr_pos[st->i] == 'x')
		ret &= f_putnbase(va_arg(st->args, unsigned int), LHEX, 1, &st->bytes);
	else if (curr_pos[st->i] == 'X')
		ret &= f_putnbase(va_arg(st->args, unsigned int), UHEX, 1, &st->bytes);
	else if (curr_pos[st->i] == '%')
		ret &= f_putchar_fd('%', 1, &st->bytes);
	else
		return (false);
	++(st->i);
	return (ret);
}

bool	handle_flag_fd(char *curr_pos, t_printf *st, int fd)
{
	bool	ret;

	++(st->i);
	ret = true;
	if (curr_pos[st->i] == 'c')
		ret &= f_putchar_fd(va_arg(st->args, int), fd, &st->bytes);
	else if (curr_pos[st->i] == 's')
		ret &= f_putstr_fd(fd, va_arg(st->args, char *), &st->bytes);
	else if (curr_pos[st->i] == 'p')
		ret &= f_putptr(va_arg(st->args, void *), fd, &st->bytes);
	else if (curr_pos[st->i] == 'd' || curr_pos[st->i] == 'i')
		ret &= f_putnbr_fd(va_arg(st->args, int), fd, &st->bytes);
	else if (curr_pos[st->i] == 'u')
		ret &= f_putunbr(va_arg(st->args, unsigned int), fd, &st->bytes);
	else if (curr_pos[st->i] == 'x')
		ret &= f_putnbase(va_arg(st->args, unsigned int), LHEX, fd, &st->bytes);
	else if (curr_pos[st->i] == 'X')
		ret &= f_putnbase(va_arg(st->args, unsigned int), UHEX, fd, &st->bytes);
	else if (curr_pos[st->i] == '%')
		ret &= f_putchar_fd('%', fd, &st->bytes);
	else
		return (false);
	++(st->i);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	t_printf	st;

	if (!format)
		return (-1);
	st.i = 0;
	st.cws = 0;
	st.bytes = 0;
	va_start(st.args, format);
	while (format[st.i])
	{
		if (format[st.i] == '%')
		{
			if (!f_putst(1, format, &st) || !handle_flag((char *)format, &st))
				return (-1);
			st.cws = st.i;
		}
		else
			st.i++;
	}
	if (!f_putst(1, format, &st))
		return (-1);
	va_end(st.args);
	return (st.bytes);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	t_printf	st;

	if (!format)
		return (-1);
	st.i = 0;
	st.cws = 0;
	st.bytes = 0;
	va_start(st.args, format);
	while (format[st.i])
	{
		if (format[st.i] == '%')
		{
			if (!f_putst(fd, format, &st)
				|| !handle_flag_fd((char *)format, &st, fd))
				return (-1);
			st.cws = st.i;
		}
		else
			st.i++;
	}
	if (!f_putst(fd, format, &st))
		return (-1);
	va_end(st.args);
	return (st.bytes);
}
