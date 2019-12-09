/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:00:52 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/09 19:30:27 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_null_s(t_data *list, char *tmp, char *str)
{
	ft_clean_counts(list);
	if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			str[list->i++] = ' ';
		if (list->point == '0')
		{
			while (tmp[list->j])
				str[list->i++] = tmp[list->j++];
		}
	}
	else if (list->minus_null == '-')
	{
		if (list->point == '0')
		{
			while (tmp[list->j])
				str[list->i++] = tmp[list->j++];
		}
		while (list->width-- != 0)
			str[list->i++] = ' ';
	}
	else if (list->minus_null == '0')
	{
		while (list->width-- != 0)
			str[list->i++] = '0';
		if (list->point == '0')
		{
			while (tmp[list->j])
				str[list->i++] = tmp[list->j++];
		}
	}
	str[list->i] = '\0';
	ft_write_and_clean_s(list, str);
}

void		ft_only_width(t_data *list, char *s, char *str, int i)
{
	int j;

	j = 0;
	if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			str[i++] = ' ';
		if (list->point == '0')
		{
			while (s[j])
				str[i++] = s[j++];
		}
	}
	else if (list->minus_null == '-')
	{
		if (list->point == '0')
		{
			while (s[j])
				str[i++] = s[j++];
		}
		while (list->width-- != 0)
			str[i++] = ' ';
	}
	else if (list->minus_null == '0')
	{
		while (list->width-- != 0)
			str[i++] = '0';
		if (list->point == '0')
		{
			while (s[j])
				str[i++] = s[j++];
		}
	}
	str[i] = '\0';
	ft_write_and_clean_s(list, str);
}

void		ft_width_s(t_data *list)
{
	if (list->accuracy != 0 && list->len != 0)
	{
		if (list->width >= list->accuracy && list->accuracy >= list->len)
			list->width = list->width - list->len;
		else if (list->width >= list->accuracy && list->accuracy <= list->len)
			list->width = list->width - list->accuracy;
		else if ((list->width <= list->accuracy && list->accuracy <= list->len)
			|| (list->width <= list->accuracy && list->accuracy >= list->len))
			list->width = 0;
	}
	else
	{
		if (list->width >= list->len)
			list->width = list->width - list->len;
		else if (list->width < list->len)
			list->width = 0;
	}
}

void		ft_s(t_data *list, va_list arg)
{
	char	*s;
	char	*str;
	int		i;

	s = NULL;
	str = NULL;
	i = 0;
	list->len = 0;
	if ((s = va_arg(arg, char *)) != NULL)
	{
		list->len = ft_strlen(s);
		if ((list->width > list->len) || (list->width == list->len))
			str = ((char *)malloc(sizeof(char) * (list->width + 1)));
		else if (list->width < list->len)
			str = ((char *)malloc(sizeof(char) * (list->len + 1)));
		ft_before(list, s, str, i);
	}
	else if (s == NULL)
		ft_null_s(list, str);
}
