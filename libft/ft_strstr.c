/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 12:11:33 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:20:44 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int taille;
	int s;
	int t;

	taille = 0;
	s = 0;
	while (to_find[taille] != '\0')
		taille++;
	if (taille == 0)
		return ((char *)str);
	while (str[s] != '\0')
	{
		t = 0;
		while (to_find[t] == str[s + t])
		{
			if (t == taille - 1)
				return ((char *)str + s);
			t++;
		}
		s++;
	}
	return (0);
}
