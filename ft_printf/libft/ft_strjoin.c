/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:55:17 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/23 20:29:20 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;

	a = NULL;
	if (s1 && s2)
	{
		if ((ft_strlen(s1) + ft_strlen(s2)) < ft_strlen(s1)
			|| ft_strlen(s1) + ft_strlen(s2) < ft_strlen(s2))
			return (NULL);
		a = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!a)
			return (NULL);
		ft_strcpy(a, s1);
		ft_strcat(a, s2);
	}
	return (a);
}
