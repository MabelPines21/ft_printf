/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:01:19 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/23 15:16:29 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	uc;

	a = (unsigned char *)arr;
	uc = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (a[i] == uc)
			return (a + i);
		else
			i++;
	}
	return (NULL);
}
