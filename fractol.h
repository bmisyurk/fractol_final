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
# include "math.h"
# include "mlx.h"
# include <stdlib.h>
# include "pthread.h"
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define W 1200
# define H 1200
# define TH (W / 8)
# define ESC 53
# define FRACT_NUM 8
# define MANDELBROT 0
# define JULIA 1
# define SHIP 2
# define M "Mandelbrot"
# define J "Julia"
# define S "Ship"

typedef struct		s_global
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	void		*img;
	int			end;
	int			bit_p_pix;
	int			s_line;
	double		x;
	double		y;
	double		i;
	double		j;
	double		c_rx;
	double		z_rx;
	double		z_iy;
	double		c_iy;
	double		tmp;
	double		max_j;
	double		zoom;
	int			max_it;
	int			it;
	int			obj;
	int			part_fr;
	int			color;
	int			color_add;
	int			julia_mouse;
	int			nfract;
	int			sfract;
	int			kind;
	int			key_height;
	int			key_width;
	int			k;
}					t_global;

void				*fractal(t_global *m);
void				*mandelbrot(void *z);
void				*julia(void *z);
void				*ship(void *transf);

void				*mandelbar(void *transf);
void				*heart(void *transf);
void				*tricorn(void *transf);
void				*celtic(void *transf);

void				mandelbrot_create(t_global *m);
void				julia_create(t_global *m);
void				ship_create(t_global *m);
void				tricorn_create(t_global *m);
void				celtic_create(t_global *m);
void				heart_create(t_global *m);
void				mandelbar_create(t_global *m);

void				num_fractol(t_global *m);
int					fract_init(t_global *m);
int					fract_init2(t_global *m);
void				launch_fract(t_global *m);

int					mouse_julia(int x, int y, t_global *m);
void				launch_threads(t_global *m);
int					mouse_zoom(int mcode, int x, int y, t_global *m);
int					key_part2(int key, t_global *m);
int					key_zoom(int key, t_global *m);
int					key_hooks(int key, t_global *m);
int					key_hook(int key, int x, int y, t_global *m);
void				pixel(t_global *m);

void				clear_window(t_global *m);
void				mlx_win_init(t_global *m);
void				put_image_mlx(t_global *m);
int					pars_fractol(t_global *m, char *argv);
void				put_pixel_to_image(t_global *m, int x, int y, int color);

int					exit_cl(void *click);
void				out_error(char *str);

#endif
