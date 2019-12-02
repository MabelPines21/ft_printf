/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:11:34 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/02 17:31:34 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_first_s(t_data *list, char *s, char *str, int i)
{
	int j;

	j = 0;
	ft_width_s(list);
	if (list->minus_null == '-')
	{
		while (s[j] && list->accuracy-- != 0)
			str[i++] = s[j++];
		while (list->width-- != 0)
			str[i++] = ' ';
	}
	else if (list->minus_null != '-')
	{
		while (list->width-- != 0)
			str[i++] = ' ';
		while (s[j] && list->accuracy != 0)
		{
			str[i++] = s[j++];
			list->accuracy--;
		}
	}
	str[i] = '\0';
	ft_write_and_clean_s(list, str);
}

void		ft_second_s(t_data *list, char *s, char *str, int i)
{
	int j;

	j = 0;
	while (s[j])
		str[i++] = s[j++];
	str[i] = '\0';
	ft_write_and_clean_s(list, str);
}

void		ft_third_s(t_data *list, char *s, char *str, int i)
{
	int j;

	j = 0;
	list->len = ft_strlen(s);
	if (list->width > list->len)
	{
		list->width = list->width - list->len;
		ft_only_width(list, s, str, i);
	}
	else if (list->width < list->len)
	{
		while (s[j])
			str[i++] = s[j++];
		str[i] = '\0';
		ft_write_and_clean_s(list, str);
	}
}

void	ft_fourth_s(t_data *list, char *s, char *str, int i)
{
	int j;
	int	len;

	j = 0;
	len = ft_strlen(s);
	if (list->accuracy > len)
	{
		while (s[j])
			str[i++] = s[j++];
	}
	else if (list->accuracy < len)
	{
		while (list->accuracy != 0)
		{
			str[i++] = s[j++];
			list->accuracy--;
		}
	}
	str[i] = '\0';
	ft_write_and_clean_s(list, str);
}

void	ft_before(t_data *list, char *s, char *str, int i)
{
	if (list->width != 0 && list->accuracy != '.')
		ft_first_s(list, s, str, i);
	else if (list->width == 0 && list->accuracy == '.')
		ft_second_s(list, s, str, i);
	else if (list->width != 0 && list->accuracy == '.')
		ft_third_s(list, s, str, i);
	else if (list->width == 0 && list->accuracy != '.')
		ft_fourth_s(list, s, str, i);
}
