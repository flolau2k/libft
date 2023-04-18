/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:59:13 by flauer            #+#    #+#             */
/*   Updated: 2023/04/18 16:29:38 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_base(size_t nbr, char *base, int fd)
{
	size_t	baselen;
	int	ret;

	ret = 0;
	baselen = ft_strlen(base);
	if (nbr < baselen)
		return (write(fd, &base[nbr], 1));
	else if (nbr >= baselen)
	{
		ret += ft_putnbr_base((nbr / baselen), base, fd);
		ret += ft_putnbr_base((nbr % baselen), base, fd);
	}
	return (ret);
}
