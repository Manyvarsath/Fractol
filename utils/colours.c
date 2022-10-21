/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:09:02 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 17:33:51 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	interpolate_colour(t_colour *c, int colour_start, int colour_end, int iter)
{
	c->r_start = (colour_start >> 16) & 0xFF;
	c->g_start = (colour_start >> 8) & 0xFF;
	c->b_start = colour_start & 0xFF;
	c->r_end = (colour_end >> 16) & 0xFF;
	c->g_end = (colour_end >> 8) & 0xFF;
	c->b_end = colour_end & 0xFF;
	c->r_iter = (c->r_end - c->r_start) * iter / MAX_ITER + c->r_start;
	c->g_iter = (c->g_end - c->g_start) * iter / MAX_ITER + c->g_start;
	c->b_iter = (c->b_end - c->b_start) * iter / MAX_ITER + c->b_start;
	return (c->r_iter << 16 | c->g_iter << 8 | c->b_iter);
}

int	coloration(t_colour *c, int iter, int medium)
{
	if (iter <= MAX_ITER / 2 - 1)
		return (interpolate_colour(c, 0x000000, medium, iter));
	else if (iter <= MAX_ITER - 1 && iter >= MAX_ITER / 2)
		return (interpolate_colour(c, medium, 0x0F0F0F0F, iter));
	return (0x000000);
}
