/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:53:07 by flauer            #+#    #+#             */
/*   Updated: 2023/04/18 16:29:28 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

bool	f_putptr(void *ptr, int fd, int *bytes_written)
{
	size_t	val;
	bool	ret;

	ret = true;
	if (!ptr)
		return (f_putstr_fd(fd, "0x0", bytes_written));
	val = (size_t) ptr;
	ret &= f_putstr_fd(fd, "0x", bytes_written);
	ret &= f_putnbase(val, LHEX, fd, bytes_written);
	return (ret);
}

bool	f_putnbase(size_t nbr, char *base, int fd, int *bytes_written)
{
	size_t	baselen;
	bool	ret;

	ret = true;
	baselen = ft_strlen(base);
	if (nbr < baselen)
		return (f_write(fd, &base[nbr], 1, bytes_written));
	else if (nbr >= baselen)
	{
		ret &= f_putnbase((nbr / baselen), base, fd, bytes_written);
		ret &= f_putnbase((nbr % baselen), base, fd, bytes_written);
	}
	return (ret);
}

bool	f_putnbr_fd(int n, int fd, int *bytes_written)
{
	bool			ret;
	unsigned int	nbr;

	ret = true;
	nbr = n;
	if (n < 0)
	{
		ret &= f_putstr_fd(fd, "-", bytes_written);
		nbr = -n;
	}
	ret &= f_putnbase(nbr, DEC, fd, bytes_written);
	return (ret);
}

bool	f_putunbr(unsigned int nbr, int fd, int *bytes_written)
{
	return (f_putnbase(nbr, DEC, fd, bytes_written));
}
