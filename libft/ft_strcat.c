/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/07 11:08:03 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 13:24:04 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int		sd;
	int		i;

	sd = 0;
	i = 0;
	while (dest[sd])
		sd++;
	while (src[i])
	{
		dest[sd + i] = src[i];
		i++;
	}
	dest[sd + i] = '\0';
	return (dest);
}
