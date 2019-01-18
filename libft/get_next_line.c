/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 09:37:18 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 16:24:31 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_readfile(int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((!ft_strchr(str, '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[0];
	int			i;
	char		*freedom;

	if (!line || fd < 0 || read(fd, NULL, 0))
		return (-1);
	if (!str[fd] && !(str[fd] = ft_strnew(0)))
		return (-1);
	str[fd] = gnl_readfile(fd, str[fd]);
	i = 0;
	if (str[fd][i])
	{
		freedom = str[fd];
		while (str[fd][i] && str[fd][i] != '\n')
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
			*line = ft_strsub(str[fd], 0, i);
		str[fd] = ft_strsub(str[fd], i + 1, ft_strlen(str[fd]) - i);
		free(freedom);
		return (1);
	}
	return (0);
}
