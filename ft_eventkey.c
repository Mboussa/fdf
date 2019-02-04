/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_eventkey.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 13:59:16 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 21:01:47 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "fdf.h"

int		push_key(int key, void *param)
{
	t_parse *tmp;

	tmp = param;
	if (key == W && tmp->zoom >= 5)
		tmp->zoom += 2;
	if (key == S && tmp->zoom > 5)
		tmp->zoom -= 2;
	if (key == NUMPAD_PLUS)
		tmp->elevation += 0.1;
	if (key == NUMPAD_LESS)
		tmp->elevation -= 0.1;
	if (key == UP)
		tmp->mouv_y -= 1;
	if (key == DOWN)
		tmp->mouv_y += 1;
	if (key == LEFT)
		tmp->mouv_x -= 1;
	if (key == RIGHT)
		tmp->mouv_x += 1;
	if (key == NUMPAD_4)
		tmp->angle_x += 0.1;
	if (key == NUMPAD_6)
		tmp->angle_x -= 0.1;
	if (key == NUMPAD_2)
		tmp->angle_y += 0.1;
	if (key == NUMPAD_8)
		tmp->angle_y -= 0.1;
	if (key == NUMPAD_0 && tmp->projection != 0)
	{
		tmp->projection = 0;
		tmp->elevation = 0;
		tmp->zoom = 5;
	}
	if (key == NUMPAD_DOT && tmp->projection != 1)
	{
		tmp->projection = 1;
		tmp->elevation = 0;
		tmp->zoom = 5;
	}
	if (key == ECHAP)
	{
		mlx_destroy_image(tmp->window.mlx_ptr, tmp->image.ptr);
		exit(1);
	}
	mlx_destroy_image(tmp->window.mlx_ptr, tmp->image.ptr);
	create_image(tmp);
	main_loop(tmp);
	return (0);
}
