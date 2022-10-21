/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:13:43 by bkamal            #+#    #+#             */
/*   Updated: 2022/10/19 17:18:14 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

//Properties
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITER 80
# define ZOOM_FACTOR 1.2
# define MOVE_FACTOR 0.05

//Hook events
# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_MOUSEMOVE 6
# define ON_DESTROY 17

//Keyboard
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define COLOUR_CHANGE 8 // key c

//Mouse
# define LCLICK 1
# define SCRD 4
# define SCRU 5 

//Structs and types
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		which;
	int		lclick;
	int		medium;
	int		inc;
	double	re_max;
	double	re_min;
	double	im_min;
	double	im_max;
	double	c_re;
	double	c_im;
	double	cap_re;
	double	cap_im;
}	t_data;

typedef struct s_colour
{
	int	r_start;
	int	g_start;
	int	b_start;
	int	r_end;
	int	g_end;
	int	b_end;
	int	r_iter;
	int	g_iter;
	int	b_iter;
	int	hex_colour;
}	t_colour;

typedef int	(*t_func)(t_data img);

/////////MANDATORY PART/////////
//Hooks
int		event_cross(t_data *mlx);
int		events_downmouse(int button, int x, int y, t_data *img);
int		events_downkey(int key, t_data *data);

//Fractals
int		table_fractals(t_data img);
void	draw_fractals(t_data *img);

//Drawing
void	upd_img(t_data *img);

//Utils
int		available_fractals(char *name, int b);
void	err_msg(void);
double	complex_r(t_data img);
double	complex_i(t_data img);

//Coloration
int		coloration(t_colour *c, int iter, int medium);

/////////BONUS PART/////////
//Hooks bonus
int		events_downkey_b(int key, t_data *data);
int		events_downmouse_b(int button, int x, int y, t_data *img);
int		events_move(int x, int y, t_data *img);

#endif