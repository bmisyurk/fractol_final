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

int		key_hooks(int key, t_global *m)
{
	key_zoom(key, m);
	key_part2(key, m);
	(key == ESC) ? exit(0) : 0;
	(key == 123) ? (m->i = m->i - 100 / m->zoom) : 0;
	(key == 124) ? (m->i += 100 / m->zoom) : 0;
	(key == 126) ? (m->j -= 100 / m->zoom) : 0;
	(key == 125) ? (m->j += 100 / m->zoom) : 0;
	(key == 13) ? (m->max_it += 2) : 0;
	(key == 12 && m->max_it > 2) ? (m->max_it -= 2) : 0;
	(key == 15) ? fract_init(m) : 0;
	(key == 14) ? (m->obj = 1) : 0;
	launch_threads(m);
	return (0);
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

int		mouse_zoom(int mcode, int x, int y, t_global *m)
{
	if (mcode == 1)
	{
		m->i = (x / m->zoom + m->i) - (x / (m->zoom * 1.35));
		m->j = (y / m->zoom + m->j) - (y / (m->zoom * 1.35));
		m->zoom *= 1.35;
	}
	if (mcode == 2)
	{
		m->i = (x / m->zoom + m->i) - (x / (m->zoom / 1.35));
		m->j = (y / m->zoom + m->j) - (y / (m->zoom / 1.35));
		m->zoom /= 1.35;
	}
	launch_threads(m);
	return (0);
}

int		key_zoom(int key, t_global *m)
{
	if (key == 69)
	{
		m->i = ((W / 2) / m->zoom + m->i) - ((W / 2) / (m->zoom * 1.35));
		m->j = ((H / 2) / m->zoom + m->j) - ((H / 2) / (m->zoom * 1.35));
		m->zoom *= 1.35;
		m->max_it++;
	}
	if (key == 78 && m->zoom > 10)
	{
		m->i = ((W / 2) / m->zoom + m->i) - ((W / 2) / (m->zoom / 1.35));
		m->j = ((H / 2) / m->zoom + m->j) - ((H / 2) / (m->zoom / 1.35));
		m->zoom /= 1.35;
		m->max_it--;
	}
	if (key == 14)
	{
		m->obj++;
		if (m->obj == 1)
			m->obj = 0;
	}
	launch_threads(m);
	return (0);
}

int		key_part2(int key, t_global *m)
{
	if (key == 49)
	{
		m->julia_mouse++;
		if (m->julia_mouse != 1)
			m->julia_mouse = 0;
	}
	if (key == 87)
	{
		m->nfract++;
		if (m->nfract == 3)
			m->nfract = 0;
		fract_init(m);
	}
	if (key == 256)
	{
		(m->nfract == 0 && m->k >= 0) ? m->k++ : 0;
		(m->nfract == 0 && m->k == 2) ? m->k = 2 : 0;
		(m->nfract == 0 && m->k == 3) ? m->k = 3 : 0;
		(m->nfract == 0 && m->k == 4) ? m->k = 4 : 0;
		(m->k == 5) ? (m->k = 0) : 0;
	}
	launch_threads(m);
	return (0);
}
