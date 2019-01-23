/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 13:44:19 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 10:41:49 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_parse *p)
{
	p->window.mlx_ptr = mlx_init();
	p->window.win_ptr = mlx_new_window(p->window.mlx_ptr, HEIGHT, WIDTH, "Moboussa - fdf");
}

double		ft_isometric_x(int x, int y)
{
	double x_iso;

	x_iso = (sqrt(2) / 2) * (x - y);
	return (x_iso);
}

double		ft_isometric_y(int x, int y, int z)
{
	double y_iso;

	y_iso = sqrt(2 / 3) * z + (1 / sqrt(6) * (x + y));
	return (y_iso);
}

void	display_p(t_parse *p)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		x1;
	int		y1;
	t_color	color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 0;
	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			x = p->zoom * i ;
			y = p->zoom * j + p->data[i][j] * p->elevation;
			x1 = p->zoom * (i + 1);
			y1 = p->zoom * j + p->data[i + 1][j] * p->elevation;
			printf("%d -- %d || %d -- %d\n", x, x1, y, y1);
			line(p, color, x, y, x1, y1);
		}
	}
	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			x = p->zoom * i + p->data[i][j] * p->elevation;
			y = p->zoom * j;	
			x1 = p->zoom * i + p->data[i][j + 1] * p->elevation;
			y1 = p->zoom * (j + 1);
			printf("%d -- %d || %d -- %d\n", x, x1, y, y1);
			line(p, color, x, y, x1, y1);
		}
	}
}

void	display_i(t_parse *p)
{
	int		i;
	int		j;
	float		x;
	float		y;
	float		x1;
	float		y1;
	t_color	color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 0;
	i = -1;
	/*while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			x = p->zoom * (sqrt(2) / 2 * (i - j)) * p->elevation;
			y = p->zoom * j * p->elevation;
			x1 = p->zoom * (sqrt(2) / 2 * ((i + 1) - j)) * p->elevation;
			y1 = p->zoom * (j + 1) * p->elevation;
			line(p, color, x, y, x1, y1);
		}
	}*/
	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			x = p->zoom * i * p->elevation;
			y = p->zoom * (sqrt(2 / 3) * p->data[i][j] - (1 / sqrt(6)) * (i + j))  * p->elevation;	
			x1 = p->zoom * (i + 1) * p->elevation;
			y1 = p->zoom * (sqrt(2 / 3) * p->data[i + 1][j] - (1 / sqrt(6)) * (i + (j + 1))) * p->elevation;
			line(p, color, x, y, x1, y1);
		}
	}
}

int		ft_event(t_parse *p, int key)
{
	if (key == 13)
		p->zoom += 2;
	if (key == 1)
		p->zoom -= 2;
	if (key == 69)
		p->elevation += 0.2;
	if (key == 78)
		p->elevation -= 0.2;
	printf("--- 1.1 ---\n");
	create_image(p);
	display_p(p);
	mlx_put_image_to_window(p->image.data, p->window.win_ptr, p->image.image, 0, 0);
	mlx_destroy_image(p->window.mlx_ptr, p->image.image);
	return (1);
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
	//printf("--- 1 ---\n");
	init_window(&p);
	printf("--- 2 ---\n");
	fill_data(&p, str);
	printf("--- 3 ---\n");
	free(str);
	printf("--- 4 ---\n");
	create_image(&p);
	printf("--- 5 ---\n");
	display_p(&p);
	//display_i(&p);
	printf("--- 6 ---\n");
	mlx_put_image_to_window(p.image.data, p.window.win_ptr, p.image.image, 500, 300);
	printf("--- 7 ---\n");
	mlx_hook(p.window.win_ptr, 2, 0, ft_event, &p);
	printf("--- 8 ---\n");
	mlx_loop(p.window.mlx_ptr);
	printf("--- 9 ---\n");
	//free_tab_int(p.data, p.line);
	close(fd);
	return (0);
}
