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
	if (argc == 2)
	{
		pars_fractol(m, argv[1]);
		num_fractol(m);
		mlx_win_init(m);
		fract_init(m);
		mlx_hook(m->win, 6, 1L < 6, mouse_julia, m);
		mlx_hook(m->win, 2, 1L << 1, key_hooks, m);
		mlx_mouse_hook(m->win, mouse_zoom, m);
		mlx_loop(m->mlx);
	}
	else
		out_error("Usage: /fractol \"mandelbrot\", \"julia\", \"ship\"");
	return (0);
}

int		pars_fractol(t_global *m, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		m->sfract = MANDELBROT;
	else if (ft_strcmp("julia", argv) == 0)
		m->sfract = JULIA;
	else if (ft_strcmp("ship", argv) == 0)
		m->sfract = SHIP;
	else
		out_error("Usage: /fractol \"mandelbrot\", \"julia\", \"ship\"");
	num_fractol(m);
	return (0);
}

void	launch_threads(t_global *m)
{
	t_global	fract[FRACT_NUM];
	pthread_t	t[FRACT_NUM];
	int			i;

	i = 0;
	clear_window(m);
	while (i < 8)
	{
		ft_memcpy((void*)&fract[i], (void*)m, sizeof(t_global));
		fract[i].y = i * TH;
		fract[i].max_j = (i + 1) * TH;
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
	{
		if (m->k == 1)
			return (tricorn);
		else if (m->k == 2)
			return (celtic);
		else if (m->k == 3)
			return (heart);
		else if (m->k == 4)
			return (mandelbar);
		else
			return (mandelbrot);
	}
	else if (m->nfract == 1)
		return (julia);
	else if (m->nfract == 2)
		return (ship);
	return (NULL);
}
