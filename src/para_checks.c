/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:16:38 by rmakoni           #+#    #+#             */
/*   Updated: 2025/02/05 10:22:53 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	list_possible_params(void)
{
	ft_printf("You have entered incorrect parameters!\n");
	ft_printf("Please enter:\n");
	ft_printf("'mandelbrot' or 'julia {imagineray no} {real no}'\n");
	ft_printf("Your possible julia sets are:\n");
	ft_printf("julia -0.4 0.6\n");
	ft_printf("julia -0.123 0.745\n");
	ft_printf("julia 0.36 0.1\n");
	ft_printf("julia -0.391 -0.587\n");
	ft_printf("julia -0.7269 0.1889\n");
	ft_printf("julia -0.75 0.0\n");
	ft_printf("julia 0.285 0.01\n");
}

// returns -1 if parameters are incorrect
// return 1 for Mandelbrot & 2 for Julia
int	check_params(int argc, char **argv)
{
	char	*str;

	str = ft_strupper(argv[1]);
	if (argc == 2)
	{
		if (ft_strncmp(str, "MANDELBROT", 10) == 0)
			return (1);
		else
			return (-1);
	}
	else if (argc == 4)
	{
		if (ft_strncmp(argv, "julia", 5) == 0)
			return (2);
		else
			return (-1);
	}
	else
		return (-1);
}
