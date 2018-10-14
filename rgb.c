#include "fractol.h"

int		palette(t_global *m)
{
	double t;
	int nn;

	m->c = (t_color *)malloc(sizeof(t_color));
	m->c->power = N * N * N;
  	t = (double)m->it/ 2;
  	m->it = (int)(t * (double)m->c->power);
  	nn = m->it - m->c->b * N * N;
 	m->c->r = nn/N;
 	m->c->g = nn - m->c->r * N;
 	m->c->b = m->it/(N * N);
	 m->it = m->c->r + m->c->g + m->c->b;
	  m->it = m->it << m->color_add;

	return (m->it);
}


