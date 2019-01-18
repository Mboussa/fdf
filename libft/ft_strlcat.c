/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 09:45:47 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 09:49:34 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t id;
	size_t isr;
	size_t j;

	i = ft_strlen(dest);
	j = 0;
	id = i;
	isr = ft_strlen((char *)src);
	if (size < id + 1)
		return (isr + size);
	if (size > id + 1)
	{
		while (i < size - 1)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	return (id + isr);
}
