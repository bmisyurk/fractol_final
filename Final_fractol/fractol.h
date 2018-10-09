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
# include <pthread.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define W			 1200
# define H		 	 800
# define ESC		 53
# define THREADS_NUM 8


# define GREY_BLUE 0x667793


typedef struct		s_comp
{
	double			c_rx;
	double			z_rx;
	double			z_iy;
	double			c_iy;
	
}					t_comp;

// typedef struct		s_i
// {
// 	double			x;
// 	double			y;
// }					t_i;

// typedef struct		s_fract
// {
// 	t_comp			y;
// 	t_comp			x;
// }					t_fract;

typedef struct      s_key
{
	double			zoom;
	int				max_it;
	int 			it;
	int				color;
	int 			fract;
}					t_key;

// typedef struct		s_dotd
// {
// 	double			x;
// 	double			y;
// }					t_dotd;

typedef struct		s_global
{

	void			*mlx;
	void			*win;
	void			*img_ptr;
	void			*img;
	int				endian;
	int             bit_per_pixel;
	int     		size_line;
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			y_max;
	t_comp			*c;
	t_key			*k;
}					t_global;

 int		hook(int mousecode, int x, int y, t_global *m);
void	ft_dezoom(int x, int y, t_global *m);
void	ft_zoom(int x, int y, t_global *m);
void	mandelbrot_calc(t_global *m);

void	*mandelbrot(void *m);
void	pars_mandelbrot(t_global *m);
void	fract_init(t_global *m);
void		pars_fractol(t_global *m, char *argv);
void	mlx_win_init(t_global *m);
// void			*draw_fract(void *p);
 int				palette(int iter, int color);
// void			mandelbrot(t_global *m, int x, int y);
// void			darken(int *col, double c);
// void			set_dotd(t_dotd *a, double x, double y);
 int				exit_cl(void *click);
 void			out_error(char *str);
 void			put_pixel_to_image(t_global *m, int x, int y, int color);
// int				key_zoom(int key, t_global *m);
// int				key_hooks(int key, t_global *m);
// void			clear_all(t_global *p);
// void			threads(t_global *p);
// int				ft_mouse_move(int x, int y, t_global *m);
// double			intpol(double start, double end, double interpolation);

#endif
