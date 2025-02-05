/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:06:53 by rmakoni           #+#    #+#             */
/*   Updated: 2025/02/05 11:45:52 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*init_fractol(char frac_type, double julia_real,
		double julia_imaginary)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (NULL);
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!fractol->mlx)
		return (free(fractol), NULL);
	fractol->mlx_img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->mlx_img)
		return (mlx_terminate(fractol->mlx), free(fractol), NULL);
	if (mlx_image_to_window(fractol->mlx, fractol->mlx_img, 0, 0) < 0)
	{
		mlx_delete_image(fractol->mlx, fractol->mlx_img);
		mlx_terminate(fractol->mlx);
		return (free(fractol), NULL);
	}
	fractol->x_offest = -0.5;
	fractol->y_offset = 0.0;
	fractol->zoom = 1.0;
	fractol->max_iterations = MAX_ITERATIONS;
	fractol->frac_type = frac_type;
	fractol->julia_imaginary = julia_imaginary;
	fractol->julia_real = julia_real;
	return (fractol);
}

void	initialise_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx, hook_key, fractol);
	mlx_scroll_hook(fractol->mlx, hook_scroll, fractol);
}
