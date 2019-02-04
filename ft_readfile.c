/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:32:51 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/02 09:37:11 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char		*takefile(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		nbr_oct;
	char	*str;

	str = ft_strnew(0);
	while ((nbr_oct = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbr_oct] = '\0';
		str = ft_strjoinf1(str, buff);
	}
	return (str);
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
