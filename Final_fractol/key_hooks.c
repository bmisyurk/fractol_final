/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:33:57 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:34:00 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int				key_move(int key, t_global *m)
{
	(key == 123) ? (m->k->move.x -= 50) : 0;
	(key == 124) ? (m->k->move.x += 50) : 0;
	(key == 126) ? (m->k->move.y -= 50) : 0;
	(key == 125) ? (m->k->move.y += 50) : 0;
	threads(m);
	return (0);
}
int	key_zoom(int key, t_global *m)
{
	double		inter;

	if (key == 69)
	{
		m->k->zoom *= 1.1;
		m->k->it++;
	}
	if (key == 78)
	{
		m->k->zoom *= 0.9;
		m->k->it++;
	}
	// p->f->shift.x -= CENTER_W - x;
	// p->f->shift.y -= CENTER_H - y;
	inter = 1.0 / m->k->zoom;
	m->f->x.min = intpol(m->mouse.x, m->f->x.min, inter);
	m->f->x.max = intpol(m->mouse.x, m->f->x.max, inter);
	m->f->y.min = intpol(m->mouse.y, m->f->y.min, inter);
	m->f->y.max = intpol(m->mouse.y, m->f->y.max, inter);
	threads(m);
	return(0);
}

int		key_hooks(int key, t_global *m)
{
	if (key == ESC)
		exit(0);
	if (key == 78 || key == 69)
		return(key_zoom(key, m));
	if (key >= 123 && key <= 126)
		return(key_move(key, m));  
	return (0);
}

double		intpol(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int				ft_mouse_move(int x, int y, t_global *m)
{
	
	m->mouse.x = x / (W / (m->f->x.max - m->f->x.min)) + m->f->x.min;
	m->mouse.y = y / (H / (m->f->y.max - m->f->y.min)) + m->f->y.min;
	// printf("x:%f\n",m->mouse.x);
	// printf("y:%f\n",m->mouse.y);
	mlx_pixel_put(m->mlx, m->win, x, y, 0xFF0000);
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
	
	return (0);
}