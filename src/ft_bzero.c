/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:34:51 by flauer            #+#    #+#             */
/*   Updated: 2023/04/21 14:22:45 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief set all bytes in buffer to 0
/// @param s pointer to first byte of buffer
/// @param n length of buffer
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
