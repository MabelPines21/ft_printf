/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:41:41 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/23 21:33:45 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*a;
	size_t	i;

	a = (char*)str;
	i = ft_strlen(str);
	while (a[i] != ch)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (a + i);
}
