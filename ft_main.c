/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 13:44:19 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 15:55:04 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_var(t_parse *p)
{
	p->up = 0.1;
	p->z = 3;
	p->mvx = 0;
	p->mvy = 0;
	p->ang_x = 0;
	p->ang_y = 0;
	p->color = 'E';
	p->base.r = 255;
	p->base.g = 255;
	p->base.b = 255;
}

void		display_p(t_parse *p)
{
	if (p->color == B)
	{
		p->base.r = 0;
		p->base.g = 0;
		p->base.b = 255;
	}
	else if (p->color == R)
	{
		p->base.r = 255;
		p->base.g = 0;
		p->base.b = 0;
	}
	else if (p->color == G)
	{
		p->base.r = 0;
		p->base.g = 255;
		p->base.b = 0;
	}
	trace_line_c1(p);
	trace_line_c2(p);
}

void		display_i(t_parse *p)
{
	if (p->color == B)
	{
		p->base.r = 0;
		p->base.g = 0;
		p->base.b = 255;
	}
	else if (p->color == R)
	{
		p->base.r = 255;
		p->base.g = 0;
		p->base.b = 0;
	}
	else if (p->color == G)
	{
		p->base.r = 0;
		p->base.g = 255;
		p->base.b = 0;
	}
	trace_line_i1(p);
	trace_line_i2(p);
}

void		main_loop(t_parse *p)
{
	if (p->projection == 1)
		display_p(p);
	else if (p->projection == 0)
		display_i(p);
	mlx_put_image_to_window(p->window.mlx_ptr, p->window.win_ptr,
	p->image.ptr, 0, 0);
	ft_display_menu(p);
	mlx_hook(p->window.win_ptr, 2, 0, push_key, p);
	mlx_loop(p->window.mlx_ptr);
}

int			main(int ac, char **av)
{
	int			fd;
	char		*str;
	t_parse		p;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) || ac != 2)
	{
		ft_putstr("usage: ./fdf		valid_map_file\n");
		return (0);
	}
	str = takefile(fd);
	init_var(&p);
	if (fill_data(&p, str) == -1 || ft_er(&p, str) == -1)
	{
		free(str);
		ft_putstr("Invalid Map\n");
		return (0);
	}
	free(str);
	init_window(&p);
	create_image(&p);
	main_loop(&p);
	close(fd);
	return (0);
}
