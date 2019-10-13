/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:39:11 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/23 18:39:12 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_text(t_global *m)
{
	mlx_string_put(m->mlx, m->win, 25, 60, 0xFFFFFF, "Fractale :");
	mlx_string_put(m->mlx, m->win, 25, 80, 0xFFFFFF, "RESET : R");
	mlx_string_put(m->mlx, m->win, 25, 100, 0xFFFFFF, "CHANGE COLOR : E");
	mlx_string_put(m->mlx, m->win, 25, 120, 0xFFFFFF,
	"NEXT FRACTOL : NUMPAD(5)");
	mlx_string_put(m->mlx, m->win, 25, 140, 0xFFFFFF, "ITERATION : Q W");
	mlx_string_put(m->mlx, m->win, 25, 160, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(m->mlx, m->win, 540, 1180, 0xFFFFFF, "CURRENT ITER: ");
	mlx_string_put(m->mlx, m->win, 25, 180, 0xFFFFFF,
	"CHANGE FORM OF FRACTOL: CTRL");
	(m->nfract == 0) ? mlx_string_put(m->mlx, m->win, 140, 60, 0xFFFFFF, M) : 0;
	(m->nfract == 1) ? mlx_string_put(m->mlx, m->win, 140, 60, 0xFFFFFF, J) : 0;
	(m->nfract == 2) ? mlx_string_put(m->mlx, m->win, 140, 60, 0xFFFFFF, S) : 0;
}

void	put_image_mlx(t_global *m)
{
	char	*max_it;

	max_it = ft_itoa(m->max_it);
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
	put_text(m);
	mlx_string_put(m->mlx, m->win, 680, 1180, 0xFFFFFF, max_it);
	if (m->nfract == 1)
		mlx_string_put(m->mlx, m->win, 25, 200, 0xFFFFFF,
		"STOP FRACTOL : SPACE");
	free(max_it);
}
