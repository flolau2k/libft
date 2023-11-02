/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:53:40 by flauer            #+#    #+#             */
/*   Updated: 2023/06/21 21:09:57 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief convert a string to an integer
/// @param str input string with decimal number
/// @return number as integer
long long	ft_atoi(const char *str)
{
	long long	ret;
	int			i;
	int			sign;

	ret = 0;
	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return (ret * sign);
}
