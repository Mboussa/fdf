/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 13:49:03 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 19:00:51 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	trace_line_c1(t_parse *p, t_color color)
{
	int		i;
	int		j;
	int		m1;
	int		m2;

	m1 = WIDTH / 2 - p->line / 2;
	m2 = HEIGHT / 2 - p->col / 2;
	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			p->y = p->z * (i + p->mvy + p->data[i][j] * p->up) + m1;
			p->x = p->z * (j + p->mvx + p->data[i][j] * p->up) + m2;
			p->y1 = p->z * ((i + 1) + p->mvy + p->data[i + 1][j] * p->up) + m1;
			p->x1 = p->z * (j + p->mvx + p->data[i + 1][j] * p->up) + m2;
			line(p, color);
		}
	}
}

void	trace_line_c2(t_parse *p, t_color color)
{
	int		i;
	int		j;
	int		m1;
	int		m2;

	m1 = WIDTH / 2 - p->line / 2;
	m2 = HEIGHT / 2 - p->col / 2;
	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			p->y = p->z * (i + p->mvy + p->data[i][j] * p->up) + m1;
			p->x = p->z * (j + p->mvx + p->data[i][j] * p->up) + m2;
			p->y1 = p->z * (i + p->mvy + p->data[i][j + 1] * p->up) + m1;
			p->x1 = p->z * ((j + 1) + p->mvx + p->data[i][j + 1] * p->up) + m2;
			line(p, color);
		}
	}
}

void	trace_line_i1(t_parse *p, t_color color)
{
	int		i;
	int		j;
	int		z;
	int		z1;

	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			z = p->mvy - p->data[i][j] * p->up + WIDTH / 2 - p->col / 2;
			z1 = p->mvy - p->data[i + 1][j] * p->up + WIDTH / 2 - p->col / 2;
			p->x = p->z * -iso_x(i, j) + p->mvx;
			p->y = p->z * -iso_y(i, j, p->data[i][j]) + z;
			p->x1 = p->z * -iso_x((i + 1), j) + p->mvx;
			p->y1 = p->z * -iso_y((i + 1), j, p->data[i + 1][j]) + z1;
			line(p, color);
		}
	}
}

void	trace_line_i2(t_parse *p, t_color color)
{
	int		i;
	int		j;
	int		z;
	int		z1;

	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			z = p->mvy - p->data[i][j] * p->up + WIDTH / 2 - p->col / 2;
			z1 = p->mvy - p->data[i][j + 1] * p->up + WIDTH / 2 - p->col / 2;
			p->x = p->z * -iso_x(i, j) + p->mvx;
			p->y = p->z * -iso_y(i, j, p->data[i][j]) + z;
			p->x1 = p->z * -iso_x(i, (j + 1)) + p->mvx;
			p->y1 = p->z * -iso_y(i, (j + 1), p->data[i][j + 1]) + z1;
			line(p, color);
		}
	}
}
