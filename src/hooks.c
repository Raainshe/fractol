/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:41:45 by rmakoni           #+#    #+#             */
/*   Updated: 2025/01/21 15:08:56 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractol->x_offest -= 0.1 * fractol->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractol->x_offest += 0.1 * fractol->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractol->y_offset += 0.1 * fractol->zoom;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractol->y_offset -= 0.1 * fractol->zoom;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
	if (fractol->frac_type == 'm' && keydata.key != MLX_KEY_ESCAPE
		&& keydata.action != MLX_PRESS)
		render_mandelbrot(fractol);
}

void	hook_scroll(double x, double y, void *param)
{
	t_fractol *fractol;

	(void)x;
	fractol = param;
	if (y > 0)
		fractol->zoom = fractol->zoom * 0.9;
	else if (y < 0)
		fractol->zoom = fractol->zoom * 1.1;
	if (fractol->frac_type == 'm')
		render_mandelbrot(fractol);
}