/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:45:56 by flauer            #+#    #+#             */
/*   Updated: 2023/07/11 14:56:25 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief locate the first occurence of char c in string s
/// @param s input string
/// @param c character to look for (converted to char)
/// @return pointer to the first occurence of c in s, NULL if c is not in s.
char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
