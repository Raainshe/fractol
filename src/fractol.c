/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:35:48 by rmakoni           #+#    #+#             */
/*   Updated: 2025/01/20 16:57:59 by rmakoni          ###   ########.fr       */
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
int	fractol_decision(char *arg)
{
	char	*str;

	str = ft_strupper(arg);
	if (ft_strncmp(str, "JULIA", 5) == 0)
		return (free(str), 2);
	else if (ft_strncmp(str, "MANDELBROT", 10) == 0)
		return (free(str), 1);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2 || fractol_decision(argv[1]) == -1)
	{
		error_msg();
		return (1);
	}
	if (fractol_decision(argv[1]) == 1)
	{
		fractol = init_fractol('m');
		if (!fractol)
			return (EXIT_FAILURE);
		initialise_hooks(fractol);
		render_mandelbrot(fractol);
		mlx_loop(fractol->mlx);
		mlx_terminate(fractol->mlx);
		free(fractol);
		return (EXIT_SUCCESS);
	}
}
