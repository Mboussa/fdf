/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 12:33:47 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 10:41:09 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, size_t size)
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
