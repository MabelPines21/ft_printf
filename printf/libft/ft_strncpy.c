/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:29:36 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/19 20:07:41 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		if (source[i] != '\0')
		{
			destination[i] = source[i];
			i++;
			n--;
		}
		else
		{
			while (n)
			{
				destination[i] = '\0';
				i++;
				n--;
			}
		}
	}
	return (destination);
}
