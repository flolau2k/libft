/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:24 by flauer            #+#    #+#             */
/*   Updated: 2023/06/21 21:09:52 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief check if input is a whitespace character
/// @param c input
/// @return 1 if whitespace, 0 if not.
int	ft_isspace(const char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
