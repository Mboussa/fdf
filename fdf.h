/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:33:40 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 15:07:17 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 1000

# include <unistd.h>
# include <stdio.h>
# include "fcntl.h"
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct	s_image
{
	void		*image;
	char		*data;
	int			bpp;
	int			s_l;
	int			endian;
}				t_image;

typedef struct	s_parse
{
	int			col;
	int			line;
	int			nbr;
	int			**data;
	t_image		image;
}				t_parse;

char			*takefile(int fd);
int				fill_data(t_parse *p, char *str);
void			line(t_window *w, int i, int j);
void			init_window(t_window *w);

#endif
