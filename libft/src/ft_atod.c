/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:25:45 by rmakoni           #+#    #+#             */
/*   Updated: 2025/02/05 10:46:27 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (('\t' <= c && '\r' >= c) || c == ' ')
		return (1);
	else
		return (0);
}

double	ft_atod(const char *str)
{
	double res;
	double sign;
	double decimal;
	double power;

	res = 0;
	sign = 1;
	decimal = 0;
	power = 1;

	while (is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		decimal = decimal * 10 + (*str++ - '0');
		power *= 10;
	}
	return (sign * (res + (decimal / power)));
}