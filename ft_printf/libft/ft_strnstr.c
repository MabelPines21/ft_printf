/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:34:11 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/24 13:40:27 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	int		i;

	len = ft_strlen(s2);
	if (len == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0' && i <= (int)(n - len))
	{
		if (s1[i] == s2[0])
			if (!ft_strncmp(s1 + i, s2, len))
				return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
