/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 14:02:04 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 12:54:38 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			fill_data(t_parse *p, char *str)
{
	char	**split1;
	char	**split2;
	int		i;
	int		j;

	i = -1;
	p->col = 0;
	split1 = ft_strsplit(str, '\n');
	p->line = ft_count_split_elems(split1);
	p->data = ft_memalloc(sizeof(int**) * p->line);
	while (++i < p->line)
	{
		j = -1;
		if (p->col == 0 && (split2 = ft_strsplit(split1[i], ' ')))
			p->col = ft_count_split_elems(split2);
		else if (p->col != ft_count_split_elems(split2 =
		ft_strsplit(split1[i], ' ')))
			return (-1);
		p->data[i] = ft_memalloc(sizeof(int*) * p->col);
		while (++j < p->col)
			p->data[i][j] = ft_atoi(split2[j]);
		free_tab_char(split2);
	}
	free_tab_char(split1);
	return (1);
}

int			ft_er(t_parse *p, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
			return (-1);
	}
	if (p->line == 1 && p->col <= 1)
		return (-1);
	return (1);
}
