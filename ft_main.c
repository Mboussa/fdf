/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 13:44:19 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/26 15:38:04 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_parse *p)
{
	p->window.mlx_ptr = mlx_init();
	p->window.win_ptr = mlx_new_window(p->window.mlx_ptr, HEIGHT, WIDTH, "Moboussa - fdf");
	p->elevation = 0.1;
	p->zoom = 5;
	p->mouv_x = 0;
	p->mouv_y = 0;
	p->angle_x = 0.1;
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

	y_iso = sqrt(2 / 3) * z - ((1 / sqrt(6)) * (x + y));
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
	color.g = 255 ;
	color.b = 255;
	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			y = p->zoom / 2 * i * cos(p->angle_y) + p->mouv_y + p->data[i][j] * cos(p->angle_x) * sin(p->angle_y) * p->elevation + WIDTH / 2 + j / 2;
			x = p->zoom / 2 * j * cos(p->angle_x) + p->mouv_x + p->data[i][j] * -sin(p->angle_x) * cos(p->angle_y) * p->elevation + HEIGHT / 2 + i / 2;
			y1 = p->zoom / 2 * (i + 1) * cos(p->angle_y) + p->mouv_y + p->data[i + 1][j] * cos(p->angle_x)  * sin(p->angle_y) * p->elevation + WIDTH / 2 + j / 2;
			x1 = p->zoom / 2 * j * cos(p->angle_x) + p->mouv_x + p->data[i + 1][j] * -sin(p->angle_x) * p->elevation + HEIGHT / 2 + i / 2;
			line(p, color, x, y, x1, y1);
		}
	}
	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			y = p->zoom / 2 * i * cos(p->angle_y) + p->mouv_y + p->data[i][j] * cos(p->angle_x) * sin(p->angle_y) * p->elevation + WIDTH / 2 + j / 2;
			x = p->zoom / 2 * j * cos(p->angle_x) + p->mouv_x + p->data[i][j] * -sin(p->angle_x) * p->elevation + HEIGHT / 2 + i / 2;
			y1 = p->zoom / 2 * i * cos(p->angle_y) + p->mouv_y + p->data[i][j + 1] * cos(p->angle_x) * sin(p->angle_y) * p->elevation + WIDTH / 2 + j / 2;
			x1 = p->zoom / 2 * (j + 1) * cos(p->angle_x) + p->mouv_x + p->data[i][j + 1] * -sin(p->angle_x) * p->elevation + HEIGHT / 2 + i / 2;
			line(p, color, x, y, x1, y1);
		}
	}
}

void	display_i(t_parse *p)
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
	i = -1;
	while (++i < p->line - 1)
	{
		j = -1;
		while (++j < p->col)
		{
			x = p->zoom / 2 * ft_isometric_x(i + p->mouv_x, j + p->mouv_y) + HEIGHT / 2 + i / 2;
			y = p->zoom / 2 * ft_isometric_y(i + p->mouv_x, j + p->mouv_y, p->data[i][j]) - p->data[i][j] * p->elevation * p->zoom / 2 + WIDTH / 2 + j / 2;
			x1 = p->zoom / 2 * ft_isometric_x((i + 1) + p->mouv_x, j + p->mouv_y) + HEIGHT / 2 + i / 2;
			y1 = p->zoom / 2 * ft_isometric_y((i + 1) + p->mouv_x, j + p->mouv_y, p->data[i + 1][j]) - p->data[i + 1][j] * p->elevation * p->zoom / 2 + WIDTH / 2 + j / 2;
			line(p, color, x, y, x1, y1);
		}
	}
	i = -1;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col - 1)
		{
			x = p->zoom / 2 * ft_isometric_x(i + p->mouv_x, j + p->mouv_y) + HEIGHT / 2 + i / 2;
			y = p->zoom / 2 * ft_isometric_y(i + p->mouv_x, j + p->mouv_y, p->data[i][j]) - p->data[i][j] * p->elevation * p->zoom / 2 + WIDTH / 2 + j / 2;
			x1 = p->zoom / 2 * ft_isometric_x(i + p->mouv_x, (j + 1) + p->mouv_y) + HEIGHT / 2 + i / 2;
			y1 = p->zoom / 2 * ft_isometric_y(i + p->mouv_x, (j + 1) + p->mouv_y, p->data[i][j + 1]) - p->data[i][j + 1] * p->elevation * p->zoom / 2 + WIDTH / 2 + j / 2;
			line(p, color, x, y, x1, y1);
		}
	}
}

void	main_loop(t_parse *p)
{
	display_i(p);
	mlx_put_image_to_window(p->window.mlx_ptr, p->window.win_ptr, p->image.ptr, 0, 0);
	mlx_hook(p->window.win_ptr, 2, 0, push_key, p);
	mlx_loop(p->window.mlx_ptr);
}

int		push_key(int key, void *param)
{
	t_parse *tmp;

	tmp = param;
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 13)
		tmp->zoom += 2;
	if (key == 1)
		tmp->zoom -= 2;
	if (key == 69)
		tmp->elevation += 0.1;
	if (key == 78)
		tmp->elevation -= 0.1;
	if (key == 126)
		tmp->mouv_y -= 5;
	if (key == 125)
		tmp->mouv_y += 5;
	if (key == 123)
		tmp->mouv_x -= 5;
	if (key == 124)
		tmp->mouv_x += 5;
	if (key == 86)
		tmp->angle_x += 0.1;
	if (key == 88)
		tmp->angle_x -= 0.1;
	if (key == 84)
		tmp->angle_y += 0.1;
	if (key == 91)
		tmp->angle_y -= 0.1;
	if (key == 53)
	{
		mlx_destroy_image(tmp->window.mlx_ptr, tmp->image.ptr);
		exit(1);
	}
	mlx_destroy_image(tmp->window.mlx_ptr, tmp->image.ptr);
	create_image(tmp);
	main_loop(tmp);
	return (0);
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
