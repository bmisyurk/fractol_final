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


int				key_hooks(int key, t_global *m)
{	
	key_zoom(key, m);
	(key == ESC) ? (exit(0)) : 0;
	(key == 123) ? (m->x1 = m->x1 - 100 / m->zoom) : 0;
	(key == 124) ? (m->x1 += 100 / m->zoom) : 0;
	(key == 126) ? (m->y1 -= 100 / m->zoom) : 0;
	(key == 125) ? (m->y1 += 100 / m->zoom) : 0;
	(key == 24)  ? (m->max_it += 3) : 0;
	(key == 27)  ? (m->max_it -= 3) : 0;
	(key == 15) ?  fract_init(m) : 0;
	(key == 18) ? (m->color_add = 4) : 0;
	(key == 19) ? (m->color_add = 8) : 0;
	(key == 20) ? (m->color_add = 16) : 0;
	if(key == 49)
    	{
    		m->julia_mouse++;
   			if (m->julia_mouse > 1)
   				m->julia_mouse = 0;
   		}
   
	launch_threads(m);
	return (0);
}


int	mouse_zoom(int mcode, int x, int y, t_global *m)
{
	if (mcode == 1)
	{
		m->x1 = (x / m->zoom + m->x1) - (x / (m->zoom * 1.35));
		m->y1 = (y / m->zoom + m->y1) - (y / (m->zoom * 1.35));
		m->zoom *= 1.35;
		m->max_it++;
	}


	if (mcode == 2)
	{
		m->x1 = (x / m->zoom + m->x1)  - (x / (m->zoom / 1.35));
		m->y1 = (y / m->zoom + m->y1) - (y / (m->zoom / 1.35));
		m->zoom /= 1.35;
		m->max_it--;
	}
	
	launch_threads(m);
	return (0);
}

int	key_zoom(int key, t_global *m)
{
	if (key == 69)
	{
		m->x1 = ((m->key_width / 2) / m->zoom + m->x1) - ((m->key_width / 2) / (m->zoom * 1.35));   
		m->y1 = ((m->key_height / 2) / m->zoom + m->y1) - ((m->key_height / 2) / (m->zoom * 1.35));
		m->zoom *= 1.35;
		m->max_it++;
	}

	if (key == 78)
	{
		m->x1 = ((m->key_width / 2) / m->zoom + m->x1)  - ((m->key_width / 2) / (m->zoom / 1.35));
		m->y1 = ((m->key_height / 2) / m->zoom + m->y1) - ((m->key_height / 2) / (m->zoom / 1.35));
		m->zoom /= 1.35;
		m->max_it--;
	}
	launch_threads(m);
	return (0);
}
