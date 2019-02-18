/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_eventkey.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 13:59:16 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 17:42:17 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	push_key0(int key, t_parse *tmp)
{
	if (key == R && tmp->color != R)
		tmp->color = R;
	if (key == G && tmp->color != G)
		tmp->color = G;
	if (key == B && tmp->color != B)
		tmp->color = B;
}

void	push_key1(int key, t_parse *tmp)
{
	if (key == W && tmp->z >= 3)
		tmp->z += 2;
	if (key == S && tmp->z > 3)
		tmp->z -= 2;
	if (key == NUMPAD_PLUS)
		tmp->up += 0.1;
	if (key == NUMPAD_LESS)
		tmp->up -= 0.1;
	if (key == UP)
		tmp->mvy -= 5;
	if (key == DOWN)
		tmp->mvy += 5;
	if (key == LEFT)
		tmp->mvx -= 5;
	if (key == RIGHT)
		tmp->mvx += 5;
	if (key == NUMPAD_4)
		tmp->ang_x += 0.1;
	if (key == NUMPAD_6)
		tmp->ang_x -= 0.1;
	if (key == NUMPAD_2)
		tmp->ang_y += 0.1;
	if (key == NUMPAD_8)
		tmp->ang_y -= 0.1;
	push_key0(key, tmp);
}

int		push_key(int key, void *param)
{
	t_parse *tmp;

	tmp = param;
	push_key1(key, tmp);
	if (key == NUMPAD_0 && tmp->projection != 0)
	{
		init_var(tmp);
		tmp->projection = 0;
	}
	if (key == NUMPAD_DOT && tmp->projection != 1)
	{
		init_var(tmp);
		tmp->projection = 1;
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
