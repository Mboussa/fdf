/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_graph.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 12:34:30 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 18:57:25 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_parse *p)
{
	p->window.mlx_ptr = mlx_init();
	p->window.win_ptr = mlx_new_window(p->window.mlx_ptr, HEIGHT, WIDTH, "Moboussa - fdf");
	p->up = 0;
	p->z = 5;
	p->mvx = 0;
	p->mvy = 0;
	p->ang_x = 0;
	p->ang_y = 0;
	p->projection = 0;
}

void	create_image(t_parse *p)
{
	p->image.ptr = mlx_new_image(p->window.mlx_ptr, HEIGHT, WIDTH);
	p->image.data = mlx_get_data_addr(p->image.ptr, &p->image.bpp, &p->image.s_l, &p->image.endian);
}

void	ft_put_pixel(t_parse *p, t_color color, int x, int y)
{
	int				i;

	i = (x * 4) + (y * p->image.s_l);
	if ((x >= 0 && x < HEIGHT) && (y >= 0 && y < WIDTH))
	{
		p->image.data[i] = color.r;
		p->image.data[i + 1] = color.g;
		p->image.data[i + 2] = color.b;
	}
}

void	line(t_parse *p, t_color color)
{
	int e2;

	p->bres.dx = abs(p->x1 - p->x);
	p->bres.sx = p->x < p->x1 ? 1 : -1;
	p->bres.dy = abs(p->y1 - p->y);
	p->bres.sy = p->y < p->y1 ? 1 : -1;
	p->bres.err = (p->bres.dx > p->bres.dy ? p->bres.dx : -p->bres.dy) / 2;
	while (1)
	{
		ft_put_pixel(p, color, p->x, p->y);
		if (p->x == p->x1 && p->y == p->y1)
			break;
		e2 = p->bres.err;
		if (e2 >-p->bres.dx)
		{
			p->bres.err -= p->bres.dy;
			p->x += p->bres.sx;
		}
		if (e2 < p->bres.dy)
		{
			p->bres.err += p->bres.dx;
			p->y += p->bres.sy;
		}
	}
}
