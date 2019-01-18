/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 12:04:12 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 10:17:22 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	tmp;

	str_len = ft_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = tmp % 10 + '0';
	while (tmp /= 10)
		str[--str_len] = tmp % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
