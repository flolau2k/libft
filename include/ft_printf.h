/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:18:17 by flauer            #+#    #+#             */
/*   Updated: 2023/06/01 15:04:59 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"
# define DEC "0123456789"

typedef struct s_printf
{
	va_list	args;
	int		bytes;
	int		i;
	int		cws;
}	t_printf;

int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
bool	f_putptr(void *ptr, int fd, int *bytes_written);
bool	f_putnbase(size_t nbr, char *base, int fd, int *bytes_written);
bool	f_putnbr_fd(int n, int fd, int *bytes_written);
bool	f_putunbr(unsigned int nbr, int fd, int *bytes_written);
size_t	ft_strlen(const char *s);
bool	f_putchar_fd(char c, int fd, int *bytes_written);
bool	f_putstr_fd(int fd, char *s, int *bytes_written);
bool	f_write(int fd, const void *buf, size_t nbyte, int *bytes_written);
bool	f_putst(int fd, const void *buf, t_printf *st);

#endif
