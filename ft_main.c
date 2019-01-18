/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 15:16:18 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 18:24:36 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_window *w)
{
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, 1280, 720, "Moboussa - fdf");
}

void	fdf(t_parse *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->line)
	{
		j = -1;
		while (++j < p->col)
			dprintf(1, "%d ", p->data[i][j]);
		dprintf(1, "\n");
		i++;
	}
}

int			main(int ac, char **av)
{
	int			fd;
	char		*str;
	t_parse		p;
	t_window	w;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	str = takefile(fd);
	p.data = NULL;
	p.col = 0;
	p.line = 0;
	printf("---1---\n");
	init_window(&w);
	printf("---2---\n");
	printf("---5---\n");
	fill_data(&p, str);
	free(str);
	printf("---6---\n");
	fdf(&p);
	printf("---7---\n");
	mlx_loop(w.mlx_ptr);
	printf("---8---\n");
	close(fd);
	return(0);
}
