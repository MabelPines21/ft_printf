/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:09:49 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/23 14:38:45 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	if (size + 1 < size)
		return (NULL);
	if ((a = (char *)malloc(sizeof(char) * (size + 1))))
	{
		ft_memset(a, (int)'\0', size + 1);
		return (a);
	}
	return (NULL);
}
