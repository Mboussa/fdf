/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 13:44:19 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 18:31:01 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		display_p(t_parse *p)
{
	t_color	color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	trace_line_c1(p, color);
	trace_line_c2(p, color);
}

void		display_i(t_parse *p)
{
	t_color	color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	trace_line_i1(p, color);
	trace_line_i2(p, color);
}

void		main_loop(t_parse *p)
{
	
	t_color	color;

	color.r = 255;
	color.g = 0;
	color.b = 0;
	if (p->projection == 0)
		display_p(p);
	if (p->projection == 1)
		display_i(p);
	mlx_put_image_to_window(p->window.mlx_ptr, p->window.win_ptr,
	p->image.ptr, 0, 0);
	mlx_hook(p->window.win_ptr, 2, 0, push_key, p);
	mlx_loop(p->window.mlx_ptr);
}

int			main(int ac, char **av)
{
	int			fd;
	char		*str;
	float		angle;
	t_parse		p;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	str = takefile(fd);
	angle = 0;
	init_window(&p);
	fill_data(&p, str);
	free(str);
	create_image(&p);
	main_loop(&p);
	close(fd);
	return (0);
}
