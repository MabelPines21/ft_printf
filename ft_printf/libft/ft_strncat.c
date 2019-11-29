/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:39:31 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/19 21:49:37 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *append, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (append[j] != '\0' && n > 0)
	{
		destination[i] = append[j];
		i++;
		j++;
		n--;
	}
	destination[i] = '\0';
	return (destination);
}
