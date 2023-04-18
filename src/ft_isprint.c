/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:34:35 by flauer            #+#    #+#             */
/*   Updated: 2023/04/18 16:28:42 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief check if input is a printable character
/// @param c input (converted to char)
/// @return return 1 if check is true, return 0 if check is false
int	ft_isprint(int c)
{
	if (ft_isascii(c) && c >= 32 && c != 127)
		return (1);
	else
		return (0);
}
