/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:52:58 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 16:56:05 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	zoom_up(t_data *img)
{
	img->im_min *= ZOOM_FACTOR;
	img->im_max *= ZOOM_FACTOR;
	img->re_max *= ZOOM_FACTOR;
	img->re_min *= ZOOM_FACTOR;
}

static void	zoom_down(t_data *img)
{
	img->im_min /= ZOOM_FACTOR;
	img->im_max /= ZOOM_FACTOR;
	img->re_max /= ZOOM_FACTOR;
	img->re_min /= ZOOM_FACTOR;
}

int	events_downmouse(int button, int x, int y, t_data *img)
{
	if (button == LCLICK && img->which == 1)
	{
		img->lclick = 1;
		img->c_im = img->im_min + y * (img->im_max - img->im_min) / HEIGHT;
		img->c_re = img->re_min + x * (img->re_max - img->re_min) / WIDTH;
		mlx_clear_window(img->mlx, img->win);
		upd_img(img);
	}
	if (button == SCRD || button == SCRU)
	{
		if (button == SCRD)
			zoom_up(img);
		else if (button == SCRU)
			zoom_down(img);
		mlx_clear_window(img->mlx, img->win);
		upd_img(img);
	}
	return (0);
}
