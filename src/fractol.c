/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:35:48 by rmakoni           #+#    #+#             */
/*   Updated: 2025/02/05 11:54:47 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup_mlx(t_fractol *fractol)
{
	if (fractol)
	{
		if (fractol->mlx_img)
			mlx_delete_image(fractol->mlx, fractol->mlx_img);
		if (fractol->mlx)
			mlx_terminate(fractol->mlx);
		free(fractol);
	}
	fractol->mlx = NULL;
	fractol->mlx_img = NULL;
}

void	error_msg(void)
{
	list_possible_params();
}

// returns -1 if parameters are incorrect
// return 1 for Mandelbrot & 2 for Julia
int	fractol_decision(char *arg)
{
	char	*str;

	str = ft_strupper(arg);
	if (!str)
		return (-1);
	if (ft_strncmp(str, "JULIA", 5) == 0)
		return (free(str), 2);
	else if (ft_strncmp(str, "MANDELBROT", 10) == 0)
		return (free(str), 1);
	else
		return (free(str), -1);
}

int	start_fractol(char *argv, double real, double imaginary)
{
	t_fractol	*fractol;

	if (fractol_decision(argv) == 1)
	{
		fractol = init_fractol('m', real, imaginary);
		if (!fractol)
			return (0);
		initialise_hooks(fractol);
		render_mandelbrot(fractol);
		mlx_loop(fractol->mlx);
		cleanup_mlx(fractol);
		return (1);
	}
	else
	{
		fractol = init_fractol('j', real, imaginary);
		if (!fractol)
			return (0);
		initialise_hooks(fractol);
		render_julia(fractol);
		mlx_loop(fractol->mlx);
		cleanup_mlx(fractol);
		return (1);
	}
}

int	main(int argc, char **argv)
{
	int	success;
	int	p_response;

	p_response = check_params(argc, argv);
	if (p_response == -1)
		return (error_msg(), EXIT_FAILURE);
	if (p_response == 1)
		success = start_fractol(argv[1], 0.0, 0.0);
	else
		success = start_fractol(argv[1], ft_atod(argv[2]), ft_atod(argv[3]));
	if (success == 1)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
