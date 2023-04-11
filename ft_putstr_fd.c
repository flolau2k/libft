/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:01:04 by flauer            #+#    #+#             */
/*   Updated: 2023/04/11 13:19:11 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief output a string to a file descriptor. Uses write()
/// @param s string
/// @param fd file descriptor
/// @returns number of bytes written
int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i += ft_putchar_fd(s[i], fd);
	}
	return (i);
}
