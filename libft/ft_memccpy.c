/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 13:21:38 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:27:15 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((char *)src)[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
