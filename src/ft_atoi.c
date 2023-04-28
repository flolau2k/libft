/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:53:40 by flauer            #+#    #+#             */
/*   Updated: 2023/04/28 11:56:37 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_isspace(const char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/// @brief convert a string to an integer
/// @param str input string with decimal number
/// @return number as integer
int	*ft_atoi(const char *str)
{
	t_atoi	st;

	st.ret = malloc(sizeof(*st.ret));
	if (!st.ret)
		return (NULL);
	st.i = 0;
	st.sign = 1;
	st.val = 0;
	while (str[st.i] && ft_isspace(str[st.i]))
		st.i++;
	if (str[st.i] == '+' || str[st.i] == '-')
	{
		if (str[st.i] == '-')
			st.sign *= -1;
		st.i++;
	}
	while (str[st.i] && ft_isdigit(str[st.i]))
	{
		st.val = (st.val * 10) + (str[st.i++] - '0');
		if ((st.sign == 1 && st.val > INT32_MAX) || (st.val > 2147483648 && st.sign == -1))
			return (free(st.ret), st.ret = NULL, NULL);
	}
	if (str[st.i] && !ft_isspace(str[st.i]))
		return (free(st.ret), st.ret = NULL, NULL);
	return (*st.ret = st.val * st.sign, st.ret);
}
