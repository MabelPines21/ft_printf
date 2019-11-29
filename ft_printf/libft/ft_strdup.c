/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:35:13 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/22 16:08:46 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*a;
	int		i;

	i = 0;
	a = NULL;
	while (str[i] != '\0')
		i++;
	a = (char *)malloc(i + 1);
	i = 0;
	if (a)
	{
		while (str[i] != '\0')
		{
			a[i] = str[i];
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
