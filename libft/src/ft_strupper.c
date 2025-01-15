/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:04:50 by rmakoni           #+#    #+#             */
/*   Updated: 2025/01/15 14:21:45 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Creates a new string with all characters converted to uppercase.
* Original string remains unchanged.
*
* @param str String to convert (can be NULL)
* @return New malloc'd string in uppercase, or NULL if str is NULL/malloc fails
*
* Example:
* ft_strupper("Hello") // returns "HELLO"
*/
char	*ft_strupper(char *str)
{
	size_t	len;
	int		i;
	char	*upper_str;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	upper_str = malloc(len + 1);
	if (!upper_str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		upper_str[i] = ft_toupper(str[i]);
		i++;
	}
	upper_str[i] = '\0';
	return (upper_str);
}
