/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:20:35 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/23 18:20:36 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*tricorn(void *transf)
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
			tricorn_create(m);
			m->y++;
		}
		m->x++;
	}
	return (transf);
}

void	tricorn_create(t_global *m)
{
	double		temp;

	m->c_rx = m->x / m->zoom + m->i;
	m->c_iy = m->y / m->zoom + m->j;
	m->z_rx = 0;
	m->z_iy = 0;
	m->it = 0;
	while (m->z_rx * m->z_rx + m->z_iy * m->z_iy < 4.0
		&& ++m->it < m->max_it)
	{
		temp = m->z_rx;
		m->z_rx = m->z_rx * m->z_rx - m->z_iy * m->z_iy + m->c_rx;
		m->z_iy = -2 * m->z_iy * temp + m->c_iy;
	}
	pixel(m);
}
