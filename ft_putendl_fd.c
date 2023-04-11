/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:34:42 by flauer            #+#    #+#             */
/*   Updated: 2023/04/11 13:20:54 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief output a string to a file descriptor, followed by a newline.
/// Uses write()
/// @param s string to output
/// @param fd file descriptor
int	ft_putendl_fd(char *s, int fd)
{
	int	ret;

	ret = 0;
	ret += ft_putstr_fd(s, fd);
	ret += ft_putchar_fd('\n', fd);
	return (ret);
}
