/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 12:33:47 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 12:36:35 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_realloc(char **dst, char *src)
{
	if (!*dst)
		*dst = ft_strdup(src);
	else
		*dst = ft_strjoinf1(*dst, src);
}
