/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:36:24 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/23 14:47:36 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*first;
	int		i;

	if (s && f)
	{
		i = 0;
		if ((first = (char *)malloc(sizeof(char)
						* ft_strlen((char *)s) + 1)))
		{
			i = 0;
			while (s[i] != '\0')
			{
				first[i] = f(s[i]);
				i++;
			}
			first[i] = '\0';
			return (first);
		}
	}
	return (NULL);
}
