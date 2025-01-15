/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:35:48 by rmakoni           #+#    #+#             */
/*   Updated: 2025/01/15 13:35:14 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(void)
{
	ft_printf("You have entered incorrect parameters.\n");
	ft_printf("Please enter: Julia OR Mandelbrot\n");
}
//returns -1 if parameters are incorrect
//return 1 for Mandelbrot & 2 for Julia
int fractol_decision(char *arg)
{
    if(ft_strupper(arg) == "JULIA")
		return 2;
	else if(ft_strupper(arg) == "MANDELBROT")
		return 1;
	else
		return -1;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
        return (error_msg, 1);
    
}
