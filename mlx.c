#include "fractol.h"

void	mlx_win_init(t_global *m)
{	
		m->key_width = W;
		m->key_height = H;
		m->mlx = mlx_init();
		m->win = mlx_new_window(m->mlx, W, H, "FRACTOL");
		m->img_ptr = mlx_new_image(m->mlx, W, H);
		m->img = mlx_get_data_addr(m->img_ptr, &m->bit_per_pixel, &m->size_line, &m->endian);
}


void	put_pixel_to_image(t_global *m, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
		*(int *)&m->img[(x * m->bit_per_pixel >> 3) +
			(y * m->size_line)] = color;
}

void	put_text(t_global *m)
{
	
	mlx_string_put(m->mlx, m->win, 20, 80, 0xFFFFFF, "ZOOM : + -");
	mlx_string_put(m->mlx, m->win, 20, 100, 0xFFFFFF, "RESET : R");
	mlx_string_put(m->mlx, m->win, 20, 120, 0xFFFFFF, "CHANGE COLOR : 1 2 3");
	mlx_string_put(m->mlx, m->win, 20, 140, 0xFFFFFF, "ITERATION : - =");
	(m->nfract == 0) ? mlx_string_put(m->mlx, m->win, 140, 60, 0xFFFFFF, M) : 0;
	(m->nfract == 1) ? mlx_string_put(m->mlx, m->win, 140, 60, 0xFFFFFF, J) : 0;
	(m->nfract == 2) ? mlx_string_put(m->mlx, m->win, 140, 60, 0xFFFFFF, S) : 0;
}

void		put_image_mlx(t_global *m)
{

	char	*max_it;
	
	max_it = ft_itoa(m->max_it);
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
	put_text(m);
	mlx_string_put(m->mlx, m->win, 20, 60, 0xFFFFFF, "Fractale : ");
	mlx_string_put(m->mlx, m->win, 600, 1180, 0xFFFFFF, "Iter : ");
	mlx_string_put(m->mlx, m->win, 680, 1180, 0xFFFFFF, max_it);
	(m->nfract == 1) ? mlx_string_put(m->mlx, m->win, 20, 160, 0xFFFFFF, "PAUSE : SPACE") : 0;
	free(max_it);
}

void			clear_window(t_global *m)
{
	int		i;
	
	i = -1;
	mlx_clear_window(m->mlx, m->win);
	while (++i < W * H)
		*(int*)&m->img[i] = 0;
}
