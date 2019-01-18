/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:04:44 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:34:34 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int lpos;

	lpos = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			lpos = i;
		i++;
	}
	if (lpos >= 0)
		return ((char *)s + lpos);
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
