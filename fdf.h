/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:33:40 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 19:23:26 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 1000
# define WIDTH 900
# define HEIGHT 1600

# include <unistd.h>
# include <stdio.h>
# include "fcntl.h"
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_window;

typedef struct		s_bres
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
}					t_bres;

typedef struct		s_image
{
	void			*ptr;
	char			*data;
	int				bpp;
	int				s_l;
	int				endian;
}					t_image;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef struct	s_parse
{
	int			col;
	int			line;
	int			nbr;
	int			zoom;
	int			mouv_x;
	int			mouv_y;
	float		angle_x;
	float		angle_y;
	float		elevation;
	int			**data;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			projection;
	t_image		image;
	t_window	window;
	t_bres		bres;
}				t_parse;

char			*takefile(int fd);
int				fill_data(t_parse *p, char *str);
void			fill_vec(t_parse *p);
void			line(t_parse *p, t_color color);
void			create_image(t_parse *p);
void			init_window(t_parse *p);
void			ft_put_pixel(t_parse *p, t_color color, int x, int y);
int				push_key(int key, void *param);
void			main_loop(t_parse *p);
double			ft_isometric_x(int x, int y);
double			ft_isometric_y(int x, int y, int z);
void			trace_line_c1(t_parse *p, t_color color);
void			trace_line_c2(t_parse *p, t_color color);
void			trace_line_i1(t_parse *p, t_color color);
void			trace_line_i2(t_parse *p, t_color color);
void			display_p(t_parse *p);
void			display_i(t_parse *p);

# define W 13
# define S 1
# define ECHAP 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define NUMPAD_0 82
# define NUMPAD_2 84
# define NUMPAD_4 86
# define NUMPAD_6 88
# define NUMPAD_8 91
# define NUMPAD_PLUS 69
# define NUMPAD_LESS 78
# define NUMPAD_DOT 65

#endif
