/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:25:21 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/22 15:25:22 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ship(void *transf)
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
			ship_create(m);
			m->y++;
		}
		m->x++;
	}
	return (transf);
}

void	ship_create(t_global *m)
{
	double temp;

	m->c_rx = m->x / m->zoom + m->i;
	m->c_iy = m->y / m->zoom + m->j;
	m->z_rx = 0;
	m->z_iy = 0;
	m->it = 0;
	while (m->z_rx * m->z_rx + m->z_iy * m->z_iy < 4.0
			&& ++m->it < m->max_it)
	{
		temp = m->z_rx * m->z_rx - m->z_iy * m->z_iy + m->c_rx;
		m->z_iy = fabs(2 * m->z_rx * m->z_iy) + m->c_iy;
		m->z_rx = fabs(temp);
	}
	if (m->it == m->max_it)
		put_pixel_to_image(m, m->x, m->y, 0x000000);
	else
		put_pixel_to_image(m, m->x, m->y, 33 * m->it * m->max_it);
}
