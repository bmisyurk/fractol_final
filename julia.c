/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:23:38 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/22 15:23:39 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*julia(void *transf)
{
	t_global	*m;
	double		temp;

	m = (t_global *)transf;
	m->x = -1;
	temp = m->y;
	while (m->x < W)
	{
		m->y = temp;
		while (m->y < m->max_j)
		{
			julia_create(m);
			m->y++;
		}
		m->x++;
	}
	return (transf);
}

void	julia_create(t_global *m)
{
	double		temp;

	m->z_rx = m->x / m->zoom + m->i;
	m->z_iy = m->y / m->zoom + m->j;
	m->it = 0;
	while (m->z_rx * m->z_rx + m->z_iy * m->z_iy < 4.0
		&& ++m->it < m->max_it)
	{
		temp = m->z_rx;
		m->z_rx = (m->z_rx * m->z_rx - m->z_iy *
		m->z_iy + (m->c_rx / W) - 0.86);
		m->z_iy = 2 * m->z_iy * temp + m->c_iy / W;
	}
	pixel(m);
}
