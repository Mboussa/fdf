/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:32:51 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 17:53:55 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static	char	*un_realloc(char *str, size_t size)
{
	char		*new;
	size_t		i;

	i = -1;
	new = ft_memalloc(sizeof(char) * size + 1);
	while (++i < size && str[i] != '\0')
		new[i] = str[i];
	free(str);
	return (new);
}

char	*takefile(int fd)
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
			str = un_realloc(str, available_space);
		}
		ft_strcpy(str, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	return (str);
}
