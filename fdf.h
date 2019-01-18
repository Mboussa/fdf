/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:33:40 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:57:20 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 1000

# include "unistd.h"
# include <stdio.h>
# include "fcntl.h"
# include <math.h>
# include "./libft/libft.h"
//# include "./minilibx_macos/mlx.h"

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			z;

}				t_pos;

typedef struct	s_parse
{
	int			col;
	int			line;
	int			nbr;
	t_pos		*data;
}				t_parse;

int				ft_count_nbr(char *str);
int				ft_count_line(char *str);
char			*takefile(int fd);
void			fill_parse(t_parse *p, char *str);
int				**char_to_int(char **tab, t_parse *p);
void			fill_data(t_parse *p, int **tab);
void			init_window(t_window *w);

#endif
