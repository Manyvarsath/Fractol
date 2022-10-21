/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:55:16 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 16:56:02 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	zoom_up(t_data *img)
{
	img->im_min = img->cap_im + (img->im_min - img->cap_im) * ZOOM_FACTOR;
	img->im_max = img->cap_im + (img->im_max - img->cap_im) * ZOOM_FACTOR;
	img->re_max = img->cap_re + (img->re_max - img->cap_re) * ZOOM_FACTOR;
	img->re_min = img->cap_re + (img->re_min - img->cap_re) * ZOOM_FACTOR;
}

static void	zoom_down(t_data *img)
{
	img->im_min = img->cap_im + (img->im_min - img->cap_im) / ZOOM_FACTOR;
	img->im_max = img->cap_im + (img->im_max - img->cap_im) / ZOOM_FACTOR;
	img->re_max = img->cap_re + (img->re_max - img->cap_re) / ZOOM_FACTOR;
	img->re_min = img->cap_re + (img->re_min - img->cap_re) / ZOOM_FACTOR;
}

int	events_move(int x, int y, t_data *img)
{
	img->cap_re = img->re_min + (double)x * (img->re_max - img->re_min) / WIDTH;
	img->cap_im = img->im_min
		+ (double)y * (img->im_max - img->im_min) / HEIGHT;
	return (0);
}

int	events_downmouse_b(int button, int x, int y, t_data *img)
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
