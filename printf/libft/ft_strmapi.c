/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:50:57 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/23 14:48:47 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*first;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		if ((first = (char *)malloc(sizeof(char)
						* ft_strlen((char *)s) + 1)))
		{
			i = 0;
			while (s[i] != '\0')
			{
				first[i] = f(i, s[i]);
				i++;
			}
			first[i] = '\0';
			return (first);
		}
	}
	return (NULL);
}
