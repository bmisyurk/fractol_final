/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:45:06 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/22 15:45:07 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel(t_global *m)
{
	if (m->obj == 1)
	{
		if (m->it < m->max_it)
			put_pixel_to_image(m, m->x, m->y, 0x000000);
		else
			put_pixel_to_image(m, m->x, m->y,
				0xFFFFFF / 80 * m->it * m->max_it);
	}
	else
	{
		if (m->it == m->max_it)
			put_pixel_to_image(m, m->x, m->y, 0x000000);
		else
			put_pixel_to_image(m, m->x, m->y,
				0xFFFFFF / 78 * m->it * m->max_it);
	}
}
