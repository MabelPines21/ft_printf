/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:59:43 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/20 16:02:23 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *app, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (dest[j] && j < size)
		j++;
	i = j;
	while (app[j - i] && j + 1 < size)
	{
		dest[j] = app[j - i];
		j++;
	}
	if (i < size)
		dest[j] = '\0';
	return (i + ft_strlen(app));
}
