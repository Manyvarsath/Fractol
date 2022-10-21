/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:30:14 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 17:19:25 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static void	not_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*pxl;

	pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)pxl = colour;
}

void	err_msg(void)
{
	write(1, "ERROR!\n", 8);
	write(1, "Mandatory part correct use:\n", 29);
	write(1, "      - ./fractol mandelbrot\n", 30);
	write(1, "      - ./fractol julia\n", 25);
	write(1, "For the bonus part, you can also try:\n", 39);
	write(1, "      - ./fractol_bonus tricorn\n", 33);
	write(1, "      - ./fractol_bonus \"burning ship\"\n", 40);
	exit (1);
}

int	available_fractals(char *name, int b)
{
	if (!my_strncmp(name, "mandelbrot", 11))
		return (0);
	else if (!my_strncmp(name, "julia", 6))
		return (1);
	else if (!my_strncmp(name, "tricorn", 8) && b == 1)
		return (2);
	else if (!my_strncmp(name, "burning ship", 13) && b == 1)
		return (3);
	else
		err_msg();
	return (-1);
}

void	draw_fractals(t_data *img)
{
	t_colour	c;
	int			iter;

	iter = 0;
	img->x = -1;
	while (++img->x < WIDTH)
	{
		img->y = -1;
		while (++img->y < HEIGHT)
		{
			if (img->lclick == 0)
			{
				img->c_re = complex_r(*img);
				img->c_im = complex_i(*img);
			}
			iter = table_fractals(*img);
			not_mlx_pixel_put(img, img->x, img->y,
				coloration(&c, iter, img->medium));
		}
	}
}
