/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:32:51 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 14:01:38 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*char			*takefile(int fd)
{
	int		read_size;
	int		available_space;
	char	*buff;
	char	*str;

	available_space = BUFF_SIZE;
	buff = ft_memalloc(sizeof(char) * BUFF_SIZE);
	str = ft_memalloc(sizeof(char) * BUFF_SIZE);
	while ((read_size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((read_size > available_space))
		{
			available_space += BUFF_SIZE;
			str = ft_realloc(str, available_space);
		}
		ft_strcpy(str, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	return (str);
}*/

char	*takefile(int fd)
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