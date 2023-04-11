/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:34:58 by flauer            #+#    #+#             */
/*   Updated: 2023/04/11 13:22:16 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief output a number as string (base 10) to a file descriptor
/// @param n integer number to output
/// @param fd file descriptor
int	ft_putnbr_fd(int n, int fd)
{
	char			out[10];
	int				i;
	unsigned int	nbr;
	int				ret;

	i = 0;
	nbr = n;
	ret = 0;
	if (n < 0)
	{
		nbr = -n;
		ret += write(fd, "-", 1);
	}
	if (n == 0)
		ret += write(fd, "0", 1);
	while (nbr > 0)
	{
		out[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	while (i-- > 0)
		ret += write(fd, out + i, 1);
	return (ret);
}
