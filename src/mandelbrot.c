/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:45:40 by rmakoni           #+#    #+#             */
/*   Updated: 2025/01/21 14:58:36 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_no	get_complex_coordinates(int x, int y, t_fractol *fractol)
{
	t_complex_no	c_no;

	c_no.real = (x - WIDTH / 2.0) * 4.0 / WIDTH * fractol->zoom
		+ fractol->x_offest;
	c_no.imaginary = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * fractol->zoom
		+ fractol->y_offset;
	return (c_no);
}

int	is_mandolbrot(t_complex_no c_no, int max_itterations)
{
	t_complex_no	z;
	double			temp;
	int				i;

	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < max_itterations)
	{
		if ((z.real * z.real + z.imaginary * z.imaginary) > 4.0)
			return (i);
		temp = z.real * z.real - z.imaginary * z.imaginary + c_no.real;
		z.imaginary = 2.0 * z.real * z.imaginary + c_no.imaginary;
		z.real = temp;
		i++;
	}
	return (max_itterations);
}

int	get_colour(int itterations, int max_itterations)
{
	int	r;
	int	g;
	int	b;

	if (itterations == max_itterations)
		return (0x000000FF);
	r = (itterations * 2) % 256;
	g = (itterations * 7) % 256;
	b = (itterations * 13) % 256;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

void	render_mandelbrot(t_fractol *fractol)
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
			iterrations = is_mandolbrot(c_no, fractol->max_iterations);
			colour = get_colour(iterrations, fractol->max_iterations);
			mlx_put_pixel(fractol->mlx_img, x, y, colour);
			x++;
		}
		y++;
	}
}
