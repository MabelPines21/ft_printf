/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:17:55 by vaisha            #+#    #+#             */
/*   Updated: 2019/08/13 14:17:55 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *destination, const void *source, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	if (destination || source)
	{
		s1 = (char*)destination;
		s2 = (char*)source;
		i = 0;
		while (n--)
		{
			s1[i] = s2[i];
			i++;
		}
		return (destination);
	}
	return (destination);
}
