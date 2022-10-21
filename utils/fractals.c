/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:00:13 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/18 20:54:40 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	mandelbrot(t_data img)
{
	double	zr;
	double	zi;
	double	hold_zr;
	double	abs;
	int		i;

	i = -1;
	zr = 0.0;
	zi = 0.0;
	abs = 0.0;
	while (abs < 4.0 && ++i < MAX_ITER)
	{
		hold_zr = (zr * zr) - (zi * zi);
		zi = (2 * zr * zi) + img.c_im;
		zr = hold_zr + img.c_re;
		abs = (zr * zr) + (zi * zi);
	}
	return (i);
}

static int	julia(t_data img)
{
	double	zr;
	double	zi;
	double	hold_zr;
	double	abs;
	int		i;

	i = -1;
	zr = img.re_min + img.x * (img.re_max - img.re_min) / WIDTH;
	zi = img.im_min + img.y * (img.im_max - img.im_min) / HEIGHT;
	abs = 0.0;
	while (abs < 4.0 && ++i < MAX_ITER)
	{
		hold_zr = (zr * zr) - (zi * zi);
		zi = (2 * zr * zi) + img.c_im;
		zr = hold_zr + img.c_re;
		abs = (zr * zr) + (zi * zi);
	}
	return (i);
}

static int	tricorn(t_data img)
{
	double	zr;
	double	zi;
	double	hold_zr;
	double	abs;
	int		i;

	i = -1;
	zr = img.c_re;
	zi = img.c_im;
	abs = 0.0;
	while (abs < 4.0 && ++i < MAX_ITER)
	{
		hold_zr = (zr * zr) - (zi * zi) + img.c_re;
		zi = -(2 * zr * zi) + img.c_im;
		zr = hold_zr;
		abs = (zr * zr) + (zi * zi);
	}
	return (i);
}

static int	burning_ship(t_data img)
{
	double	zr;
	double	zi;
	double	hold_zr;
	double	abs;
	int		i;

	i = -1;
	zr = img.c_re;
	zi = img.c_im;
	abs = 0.0;
	while (abs < 4.0 && ++i < MAX_ITER)
	{
		hold_zr = (zr * zr) - (zi * zi) + img.c_re;
		zi = fabs(2 * zr * zi) + img.c_im;
		zr = hold_zr;
		abs = (zr * zr) + (zi * zi);
	}
	return (i);
}

int	table_fractals(t_data img)
{
	t_func	fractal[4];

	fractal[0] = mandelbrot;
	fractal[1] = julia;
	fractal[2] = tricorn;
	fractal[3] = burning_ship;
	return (fractal[img.which](img));
}
