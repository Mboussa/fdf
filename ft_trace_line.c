/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 13:49:03 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 21:14:04 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	trace_line_c1(t_parse *p, t_color color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			p->y = p->zoom / 2 * (i + p->mouv_y + p->data[i][j] * p->elevation) + (WIDTH / 2 - p->line / 2);
			p->x = p->zoom / 2 * (j + p->mouv_x + p->data[i][j] * p->elevation) + (HEIGHT / 2 - p->col / 2);
			p->y1 = p->zoom / 2 * ((i + 1) + p->mouv_y + p->data[i + 1][j] * p->elevation) + (WIDTH / 2 - p->line / 2);
			p->x1 = p->zoom / 2 * (j + p->mouv_x + p->data[i + 1][j] * p->elevation) + (HEIGHT / 2 - p->col / 2);
			line(p, color);
		}
	}
}

void	trace_line_c2(t_parse *p, t_color color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			p->y = p->zoom / 2 * (i + p->mouv_y + p->data[i][j] * p->elevation) + (WIDTH / 2 - p->line / 2);
			p->x = p->zoom / 2 * (j + p->mouv_x + p->data[i][j]  * p->elevation) + (HEIGHT / 2 - p->col / 2);
			p->y1 = p->zoom / 2 * (i + p->mouv_y + p->data[i][j + 1] * p->elevation) + (WIDTH / 2 - p->line / 2);
			p->x1 = p->zoom / 2 * ((j + 1) + p->mouv_x + p->data[i][j + 1] * p->elevation) + (HEIGHT / 2 - p->col / 2);
			line(p, color);
		}
	}
}

void	trace_line_i1(t_parse *p, t_color color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			p->x = p->zoom / 2 * -ft_isometric_x(i + p->mouv_x, j + p->mouv_y) + HEIGHT / 2 - p->line / 2;
			p->y = p->zoom / 2 * -ft_isometric_y(i + p->mouv_x, j + p->mouv_y, p->data[i][j]) - p->data[i][j] * p->elevation + WIDTH / 2 - p->col / 2;
			p->x1 = p->zoom / 2 * -ft_isometric_x((i + 1) + p->mouv_x, j + p->mouv_y) + HEIGHT / 2 - p->line / 2;
			p->y1 = p->zoom / 2 * -ft_isometric_y((i + 1) + p->mouv_x, j + p->mouv_y, p->data[i + 1][j])- p->data[i + 1][j] * p->elevation + WIDTH / 2 - p->col / 2;
			line(p, color);
		}
	}
}

void	trace_line_i2(t_parse *p, t_color color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			p->x = p->zoom / 2 * -ft_isometric_x(i + p->mouv_x, j + p->mouv_y) + HEIGHT / 2 - p->line / 2;
			p->y = p->zoom / 2 * -ft_isometric_y(i + p->mouv_x, j + p->mouv_y, p->data[i][j])- p->data[i][j] * p->elevation + WIDTH / 2 - p->col / 2;
			p->x1 = p->zoom / 2 * -ft_isometric_x(i + p->mouv_x, (j + 1) + p->mouv_y) + HEIGHT / 2 - p->line / 2;
			p->y1 =p->zoom / 2 *  -ft_isometric_y(i + p->mouv_x, (j + 1) + p->mouv_y, p->data[i][j + 1]) - p->data[i][j + 1] * p->elevation + WIDTH / 2 - p->col / 2;
			line(p, color);
		}
	}
}
