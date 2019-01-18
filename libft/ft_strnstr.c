/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 13:22:05 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 10:01:15 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, char *need, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	str = (char *)hay;
	i = 0;
	j = 0;
	size = 0;
	size = ft_strlen(need);
	if (size == 0)
		return (str);
	while (len > i && str[i])
	{
		while (len > (i + j) && need[j] == str[i + j])
		{
			if (j == size - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
