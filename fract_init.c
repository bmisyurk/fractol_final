/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:08:11 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/22 15:08:18 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	num_fractol(t_global *m)
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
	m->obj = 0;
	if (m->nfract == 0)
	{
		m->k = 0;
		m->i = -2.5;
		m->j = -2;
		m->max_it = 60;
		m->zoom = 300;
	}
	else if (m->nfract == 1)
	{
		m->i = -2;
		m->j = -2;
		m->c_rx = -0.7269;
		m->c_iy = -0.3842;
		m->julia_mouse = 0;
		m->max_it = 80;
		m->zoom = 300;
	}
	fract_init2(m);
	return (0);
}

int		fract_init2(t_global *m)
{
	if (m->nfract == 2)
	{
		m->k = 0;
		m->obj = 2;
		m->i = -2;
		m->j = -2;
		m->max_it = 77;
		m->zoom = 300;
	}
	launch_threads(m);
	return (0);
}
