/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:48:24 by flauer            #+#    #+#             */
/*   Updated: 2023/04/18 16:29:33 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/libft.h"

/// @brief output character to file descriptor. Uses write()
/// @param c character to output
/// @param fd file descriptor to output to
int	ft_putchar_fd(char c, int fd)
{
	int	ret;

	ret = 0;
	ret = write(fd, &c, 1);
	return (ret);
}
