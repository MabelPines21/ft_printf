/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:17:28 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/20 14:43:38 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	char	*str;
	int		i;

	str = destination;
	i = 0;
	while (n != 0)
	{
		str[i] = c;
		n--;
		i++;
	}
	return (str);
}
