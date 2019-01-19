/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:32:51 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 10:40:18 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char			*takefile(int fd)
{
	int		read_size;
	int		str_len;
	int		available_space;
	char	*buff;
	char	*str;

	available_space = BUFF_SIZE;
	str_len = 0;
	buff = ft_memalloc(sizeof(char) * BUFF_SIZE);
	str = ft_memalloc(sizeof(char) * BUFF_SIZE);
	while ((read_size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((str_len + read_size > available_space))
		{
			available_space += BUFF_SIZE;
			str = ft_realloc(str, available_space);
		}
		ft_strcpy(str, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	return (str);
}
