/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 14:02:04 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:57:45 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	fill_parse(t_parse *p, char *str)
{
	p->nbr = ft_count_nbr(str);
	p->line = ft_count_line(str);
	p->col = p->nbr / p->line;
}

int		ft_count_nbr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			count++;
		if (str[i] != ' ' && str[i + 1] != ' ' && str[i + 1] != '\n')
			count--;
		i++;
	}
	return (count);
}

int		ft_count_line(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		**char_to_int(char **tab, t_parse *p)
{
	int		i;
	int		j;
	int		a;
	int		**dest;

	i = -1;
	a = 0;
	if (!(dest = (int **)malloc(sizeof(int *) * p->line)))
		return (0);
	while (++i < p->line)
	{
		if (!(dest[i] = (int *)malloc(sizeof(int) * p->col)))
			return (0);
		j = -1;
		while (++j < p->col)
		{
			dest[i][j] = ft_atoi(tab[a]);
			a++;
		}
	}
	return (dest);
}

void	fill_data(t_parse *p, int **tab)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	a = 0;
	if (!(p->data = malloc(sizeof(int) * p->nbr)))
		return ;
	while (++i < p->line)
	{
		j = -1;
		while (++j < p->col)
		{
			p->data[a].x = i;
			p->data[a].y = j;
			p->data[a].z = tab[i][j];
			a++;
		}
	}
}
