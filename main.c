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


#include "fractol.h"

int		main(int argc, char **argv)
{
	t_global	*m;

	
	if (!(m = (t_global*)malloc(sizeof(t_global))))
		out_error("error");
		if(argc == 2)
	{
		mlx_win_init(m);

		pars_fractol(m, argv[1]);

		fract_init(m);


		mlx_hook(m->win, 6, 1L < 6, mouse_julia, m);
		mlx_hook(m->win, 17, 1L << 17, exit_cl, m);
		mlx_hook(m->win, 2, 1L << 1, key_hooks, m);
		mlx_mouse_hook(m->win, mouse_zoom, m);

		mlx_loop(m->mlx);



	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
	return (0);
}

void		pars_fractol(t_global *m, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		m->sfract = MANDELBROT;
	else if (ft_strcmp("julia", argv) == 0)
		m->sfract = JULIA;
	else if (ft_strcmp("ship", argv) == 0)
		m->sfract = SHIP;
	num_fractol(m);
}

void		num_fractol(t_global *m)
{
	if (m->sfract == MANDELBROT)
		m->nfract = 0;
	else if (m->sfract == JULIA)
		m->nfract = 1;
	else if (m->sfract == SHIP)
		m->nfract = 2;
}


int		fract_init(t_global *m)
{
	if (m->nfract == 0)
	{
		m->max_it = 60;
		m->zoom = 300;
		m->x1 = -2;
		m->y1 = -2;
	}
	else if (m->nfract == 1)
	{
		m->c_rx = -0.70176;
		m->c_iy = -0.3842;
		m->julia_mouse = 0;
		m->x1 = -2.0;
		m->y1 = -1.9;
		m->max_it = 80;
		m->zoom = 300;
	}

	launch_threads(m);
	return (0);
}


void	launch_threads(t_global *m)
{
	t_global	fract[THREADS_NUM];
	pthread_t	t[THREADS_NUM];
	int			i;
	i = 0;
	clear_window(m);
	while (i < 8)
	{
		ft_memcpy((void*)&fract[i], (void*)m, sizeof(t_global));
		fract[i].y = 150 * i;
		fract[i].y_max = 150 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, fractal(m), &fract[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);

	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
	put_image_mlx(m);
	
}
void	*fractal(t_global *m)
{
	if (m->nfract == 0)
		return (mandelbrot);
	 else if (m->nfract == 1)
	 	return (julia);
	return (NULL);
}
void	*mandelbrot(void *n)
{

	t_global	*m;
	double		tmp;

	m = (t_global *)n;

	m->x = 0; 
	tmp = m->y;
	while (m->x < W)
	{
		m->y = tmp;

		while (m->y < m->y_max)
		{
			mandelbrot_create(m);
			m->y++;
		}
		m->x++;
	}
	return (n);

}

void	*julia(void *n)
{

	t_global	*m;
	double		tmp;

	m = (t_global *)n;

	m->x = 0; 
	tmp = m->y;
	while (m->x < W)
	{
		m->y = tmp;

		while (m->y < m->y_max)
		{
			julia_create(m);
			m->y++;
		}
		m->x++;
	}
	return (n);

}
int		mouse_julia(int x, int y, t_global *m)
{
	if (m->nfract == 1 && m->julia_mouse == 0)
	{
		m->c_rx = x * 1.3;
		m->c_iy = y * 1.3;
		launch_threads(m);
	}
	return (0);
}
void	julia_create(t_global *m)
{
	double		temp;

	
	m->z_rx = m->x / m->zoom + m->x1;
	m->z_iy = m->y / m->zoom + m->y1;;
	m->it = 0;

	while (m->z_rx * m->z_rx + m->z_iy * m->z_iy  < 4 && ++m->it < m->max_it)
	{
		temp = m->z_rx;
		m->z_rx = m->z_rx * m->z_rx - m->z_iy * m->z_iy + (m->c_rx / W) - 0.77;
		m->z_iy = 2 * m->z_iy * temp + m->c_iy / W;
		
		
	}

	if (m->it >= m->max_it)
		put_pixel_to_image(m, m->x, m->y, 0x000000);
	else
	{
		put_pixel_to_image(m, m->x, m->y, palette(m));

	}

}

void	mandelbrot_create(t_global *m)
{
	double		temp;

	m->c_rx = m->x / m->zoom + m->x1;
	m->c_iy = m->y / m->zoom + m->y1;
	m->z_rx = 0;
	m->z_iy = 0;
	m->it = 0;

	while (m->z_rx * m->z_rx + m->z_iy * m->z_iy  < 4 && ++m->it < m->max_it)
	{
		temp = m->z_rx;
		m->z_rx = m->z_rx * m->z_rx - m->z_iy * m->z_iy + m->c_rx;
		m->z_iy = 2 * m->z_iy * temp + m->c_iy;
		
	}

	if (m->it >= m->max_it)
		put_pixel_to_image(m, m->x, m->y, 0x000000);
	else
	{
		put_pixel_to_image(m, m->x, m->y, palette(m));

	}

}

