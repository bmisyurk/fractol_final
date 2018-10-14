/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:47:01 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/25 12:47:02 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "pthread.h"
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define W			 1200
# define H		 	 1200
# define ESC		 53
# define THREADS_NUM 8
# define MANDELBROT 0
# define JULIA 1
# define SHIP 2
# define N 265
# define M "Mandelbrot"
# define J "Julia"
# define S "Ship"
# define GREY_BLUE 0x667793

typedef struct      s_color
{
	int		r;
	int		g;
	int		b;
	int		power;
	signed	num;
		
}					t_color;

typedef struct		s_global
{
	int             julia_mouse;
	int 			color_add;
	void			*mlx;
	void			*win;
	void			*img_ptr;
	void			*img;
	int				endian;
	int             bit_per_pixel;
	int     		size_line;
	double			x;
	double			y;
	double			tmp;
	double			x1;
	double			y1;
	double			y_max;
	double			zoom;
	int				max_it;
	int 			it;
	int				color;
	int 			nfract;
	int			sfract;
	int				kind;
	int				key_height;
	int				key_width;
	double			c_rx;
	double			z_rx;
	double			z_iy;
	double			c_iy;
	t_color			*c;
}					t_global;

int		mouse_julia(int x, int y, t_global *m);
void		clear_window(t_global *m);
void		launch_threads(t_global *m);
void		put_image_mlx(t_global *m);
void		*fractal(t_global *m);
void		launch_fract(t_global *m);
int			mouse_zoom(int mcode, int x, int y, t_global *m);
int			key_zoom(int key, t_global *m);
int			key_hooks(int key, t_global *m);
void		num_fractol(t_global *m);
void		mandelbrot_create(t_global *m);
int			key_hook(int key, int x, int y, t_global *m);
void		*mandelbrot(void *m);
void		pars_fract(t_global *m);
int			fract_init(t_global *m);
void		pars_fractol(t_global *m, char *argv);
void		mlx_win_init(t_global *m);
int			palette(t_global *m);
 int		exit_cl(void *click);
 void		out_error(char *str);
 void		put_pixel_to_image(t_global *m, int x, int y, int color);
 void	julia_create(t_global *m);
void	*julia(void *n);


#endif
