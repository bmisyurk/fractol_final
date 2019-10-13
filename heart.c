/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:18:20 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/23 18:18:21 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*heart(void *transf)
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
			heart_create(m);
			m->y++;
		}
		m->x++;
	}
	return (transf);
}

void	heart_create(t_global *m)
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
		m->z_iy = m->z_iy * fabs(temp) * 2.0 + m->c_iy;
	}
	pixel(m);
}
