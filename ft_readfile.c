/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:32:51 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 17:32:32 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char	*takefile(int fd)
{
	char	*line;
	char	*str;

	str = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_realloc(&str, line);
		ft_realloc(&str, " \n");
		ft_strdel(&line);
	}
	return (str);
}
