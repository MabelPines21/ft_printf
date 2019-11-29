/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:57:39 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/19 12:05:57 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *dest, const char *find)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (find[res] != '\0')
		res++;
	if (res == 0)
		return ((char *)dest);
	while (dest[i] != '\0')
	{
		while (find[j] == dest[i + j])
		{
			if (j == res - 1)
				return ((char *)dest + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
