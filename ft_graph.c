/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_graph.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 12:34:30 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 14:42:20 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

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

void	line(t_parse *p, t_color color, int i, int j, int i1, int j1)
{
	int dx = abs(i1 - i);
	int sx = i < i1 ? 1 : -1;
	int dy = abs(j1 - j);
	int sy = j < j1 ? 1 : -1; 
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;
	while (1)
	{
		ft_put_pixel(p, color, i, j);
		if (i == i1 && j == j1)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			i += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			j += sy;
		}
	}
}
