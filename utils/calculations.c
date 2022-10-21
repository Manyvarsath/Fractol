/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:07:02 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 16:10:40 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	complex_r(t_data img)
{
	if (img.which == 0 || img.which == 2 || img.which == 3)
		return (img.re_min + (double)img.x * (img.re_max - img.re_min) / WIDTH);
	return (1 - (1 + sqrt(5)) / 2);
}

double	complex_i(t_data img)
{
	if (img.which == 0 || img.which == 2 || img.which == 3)
		return (img.im_min + (double)img.y
			* (img.im_max - img.im_min) / HEIGHT);
	return (0.0);
}
