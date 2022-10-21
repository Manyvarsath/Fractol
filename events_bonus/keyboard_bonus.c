/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:51:55 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 17:04:36 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	move(t_data *data, int which)
{
	if (which == 1)
	{
		data->im_min += (data->im_max - data->im_min) * MOVE_FACTOR;
		data->im_max += (data->im_max - data->im_min) * MOVE_FACTOR;
	}
	else if (which == 2)
	{
		data->im_min -= (data->im_max - data->im_min) * MOVE_FACTOR;
		data->im_max -= (data->im_max - data->im_min) * MOVE_FACTOR;
	}
	else if (which == 3)
	{
		data->re_min += (data->re_max - data->re_min) * MOVE_FACTOR;
		data->re_max += (data->re_max - data->re_min) * MOVE_FACTOR;
	}
	else if (which == 4)
	{
		data->re_min -= (data->re_max - data->re_min) * MOVE_FACTOR;
		data->re_max -= (data->re_max - data->re_min) * MOVE_FACTOR;
	}
}

static void	change_colour(t_data *data)
{
	if (data->inc == 0)
		data->medium += 0xCC9911;
	if (data->inc == 1)
		data->medium += 0xFF91AF;
	if (data->inc == 2)
		data->medium += 0x801818;
	if (data->inc == 3)
		data->medium += 0x08B07C;
	if (data->inc == 4)
		data->medium += 0xE3256B;
	if (data->inc == 5)
		data->medium += 0x4EA809;
	if (data->inc == 6)
		data->medium += 0x592720;
	if (data->inc == 7)
		data->medium += 0xFD7F4F;
	if (data->inc == 8)
		data->medium += 0x947706;
	if (data->inc == 9)
	{
		data->medium += 0xF6F6FF;
		data->inc = -1;
	}
	data->inc++;
}

int	events_downkey_b(int key, t_data *data)
{
	if (key == ESC)
		exit (0);
	if (key == DOWN)
		move(data, 1);
	if (key == UP)
		move(data, 2);
	if (key == RIGHT)
		move(data, 3);
	if (key == LEFT)
		move(data, 4);
	if (key == COLOUR_CHANGE)
		change_colour(data);
	mlx_clear_window(data->mlx, data->win);
	upd_img(data);
	return (0);
}
