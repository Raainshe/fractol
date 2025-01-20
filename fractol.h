/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:35:51 by rmakoni           #+#    #+#             */
/*   Updated: 2025/01/20 16:55:14 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 50;

typedef struct s_complex_no
{
	double		real;
	double		imaginary;
}				t_complex_no;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
	double		x_offest;
	double		y_offset;
	double		zoom;
	int			max_iterations;
	char		frac_type;

}				t_fractol;

void			render_mandelbrot(t_fractol *fractol);
void			hook_key(mlx_key_data_t keydata, void *param);
void			hook_scroll(double x, double y, void *param);
t_fractol		*init_fractol(char frac_type);
void			initialise_hooks(t_fractol *fractol);

#endif