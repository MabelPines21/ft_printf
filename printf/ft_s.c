/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:00:52 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/19 14:55:53 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_only_width(t_data *list, char *s, char *str, int i)
{
	int j;

	j = 0;
	if (list->minus_null != '-')
	{
		while (list->width-- != 0)
			str[i++] = ' ';
		while (s[j])
			str[i++] = s[j++];
	}
	else if (list->minus_null == '-')
	{
		while (s[j])
			str[i++] = s[j++];
		while (list->width-- != 0)
			str[i++] = ' ';
	}
	str[i] = '\0';
	ft_write_and_clean_s(list, str);
}

void		ft_width_s(t_data *list, char *s)
{
	int len;

	len = ft_strlen(s);
	if (list->width >= list->accuracy && list->accuracy >= len)
		list->width = list->width - len;
	else if (list->width >= list->accuracy && list->accuracy <= len)
		list->width = list->width - list->accuracy;
	else if ((list->width <= list->accuracy && list->accuracy <= len)
		|| (list->width <= list->accuracy && list->accuracy >= len))
		list->width = 0;
}

void		ft_s(t_data *list, va_list arg)
{
	char	*s;
	char	*str;
	int		i;
	int		len;

	s = NULL;
	str = NULL;
	i = 0;
	s = va_arg(arg, char *);
	len = ft_strlen(s);
	if (list->width > len)
		str = ((char *)malloc(sizeof(char) * (list->width + 1)));
	else if (list->width < len)
		str = ((char *)malloc(sizeof(char) * (len + 1)));
	else if (list->width == len)
		str = ((char *)malloc(sizeof(char) * (list->width + 1)));
	ft_before(list, s, str, i);
}
