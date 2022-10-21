/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:14:18 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 17:24:28 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	init_window(t_data *img, char *name)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "fractol");
	img->which = available_fractals(name, 0);
	img->medium = 0x0DF1AB;
	img->lclick = 0;
	img->re_min = -2.0;
	img->re_max = 2.0;
	img->im_min = -2.0;
	img->im_max = 2.0;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_fractals(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

static void	all_hooks(t_data *mlx)
{
	mlx_hook(mlx->win, ON_KEYDOWN, 0, events_downkey, mlx);
	mlx_hook(mlx->win, ON_MOUSEDOWN, 0, events_downmouse, mlx);
	mlx_hook(mlx->win, 17, 0, event_cross, mlx);
}

void	upd_img(t_data *img)
{
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	draw_fractals(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(t_data));
	if (ac != 2 || available_fractals(av[1], 0) == -1)
		err_msg();
	init_window(img, av[1]);
	all_hooks(img);
	mlx_loop(img->mlx);
	return (0);
}
