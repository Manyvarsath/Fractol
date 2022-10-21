/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:21:38 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/18 19:43:25 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	events_downkey(int key, t_data *data)
{
	(void)data;
	if (key == ESC)
		exit (0);
	return (0);
}

int	event_cross(t_data *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}
