/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 09:56:26 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 10:00:51 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		size;
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[size - 1] == ' ' || s[size - 1] == '\t' || s[size - 1] == '\n')
		size--;
	dest = ft_strsub(s, i, size - i);
	if (dest == NULL)
		return (ft_strdup(""));
	return (dest);
}
