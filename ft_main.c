/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 15:16:18 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 14:32:57 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_window *w)
{
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, 1280, 720, "Moboussa - fdf");
}

void	display(t_window *w, t_parse *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col - 1)
			line(w, i, j);
	}
}

int			main(int ac, char **av)
{
	int			fd;
	char		*str;
	float		angle;
	t_parse		p;
	t_window	w;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	str = takefile(fd);
	angle = 0;
	init_window(&w);
	fill_data(&p, str);
	free(str);
	display(&w, &p);
	mlx_loop(w.mlx_ptr);
	close(fd);
	return (0);
}
