/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:34:58 by flauer            #+#    #+#             */
/*   Updated: 2023/04/18 16:29:41 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief output a number as string (base 10) to a file descriptor
/// @param n integer number to output
/// @param fd file descriptor
int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				ret;

	ret = 0;
	nbr = n;
	if (n < 0)
	{
		ret += ft_putstr_fd("-", fd);
		nbr = -n;
	}
	ret += ft_putnbr_base(nbr, DEC, fd);
	return (ret);
}
