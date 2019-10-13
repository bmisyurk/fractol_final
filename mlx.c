/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:17:27 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/22 15:17:32 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_win_init(t_global *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, W, H, "FRACTOL");
	m->img_ptr = mlx_new_image(m->mlx, W, H);
	m->img = mlx_get_data_addr(m->img_ptr, &m->bit_p_pix, &m->s_line, &m->end);
}

void	put_pixel_to_image(t_global *m, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
		*(int *)&m->img[(x * m->bit_p_pix >> 3) +
			(y * m->s_line)] = color;
}

void	clear_window(t_global *m)
{
	int	i;

	i = -1;
	mlx_clear_window(m->mlx, m->win);
	while (++i < W * H)
		*(int*)&m->img[i] = 0;
}
