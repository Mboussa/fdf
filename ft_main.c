/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 15:16:18 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:58:30 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*void		init_window(t_window *w)
{
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, 1280, 720, "Moboussa - fdf");
}*/

void	line(t_var *v, t_window *w)
{
	int dx = abs(v->x1 - v->x0);
	int sx = v->x0 < v->x1 ? 1 : -1;
	int dy = abs(v->y1 - v->y0);
	int sy = v->y0 < v->y1 ? 1 : -1; 
	int err = (dx > dy ? dx : - dy) / 2;
	int e2;

	while (1)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, v->x0, v->y0, 0xFFFFFF);
		if (v->x0 == v->x1 && v->y0 == v->y1)
			break;
		e2 = err;
		if (e2 > - dx)
		{
			err -= dy;
			v->x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			v->y0 += sy;
		}
	}
}

int			main(int ac, char **av)
{
	int			fd;
	char		*str;
	char		**tab;
	int			**dest;
	t_parse		p;
	//t_window	w;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	str = takefile(fd);
	fill_parse(&p, str);
	tab = ft_strsplit(str, ' ');
	dest = char_to_int(tab, &p);
	fill_data(&p, dest);
	//init_window(&w);
	//mlx_loop(w.mlx_ptr);
	free(str);
	free_tab_char(tab);
	free_tab_int(dest, p.line);
	free(p.data);
	close(fd);
	return(0);
}
