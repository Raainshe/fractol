/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:04:26 by rmakoni           #+#    #+#             */
/*   Updated: 2025/02/05 13:54:15 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_julia(t_complex_no c_no, int max_itterations, t_fractol *fractol)
{
	t_complex_no	z;
	t_complex_no	x;
	double			temp;
	int				i;

	z = c_no;
	x.imaginary = fractol->julia_imaginary;
	x.real = fractol->julia_real;
	i = 0;
	while (i < max_itterations)
	{
		if ((z.real * z.real + z.imaginary * z.imaginary) > 4.0)
			return (i);
		temp = z.real * z.real - z.imaginary * z.imaginary + x.real;
		z.imaginary = 2.0 * z.real * z.imaginary + x.imaginary;
		z.real = temp;
		i++;
	}
	return (max_itterations);
}

void	render_julia(t_fractol *fractol)
{
	int				x;
	int				y;
	t_complex_no	c_no;
	int				iterrations;
	int				colour;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_no = get_complex_coordinates(x, y, fractol);
			iterrations = is_julia(c_no, fractol->max_iterations, fractol);
			colour = get_colour(iterrations, fractol->max_iterations);
			mlx_put_pixel(fractol->mlx_img, x, y, colour);
			x++;
		}
		y++;
	}
}
