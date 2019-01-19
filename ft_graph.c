/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_graph.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 12:34:30 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 15:08:44 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_parse *p, t_window *w)
{
	p->image.image = mlx_new_image(w->mlx_ptr, 1280, 720);
	p->image.data = mlx_get_data_addr(p->image.image, &p->image.bpp, &p->image.s_l, &p->image.endian);
}

void	ft_fill_pixel(t_parse *p, int x, int y, int color)
{

}

void	line(t_window *w, int i, int j)
{
	int dx = abs(i + 1 - i);
	int sx = i < i + 1 ? 1 : -1;
	int dy = abs(j + 1 - j);
	int sy = j < j + 1 ? 1 : -1; 
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, j, i, 0x55FF33);
		if (i == i + 1 && j == j + 1)
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