/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remember.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:51:59 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/02 17:24:55 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rem_flag(const char *format, int i, t_data *list)
{

	if (format[i] == '+')
		list->plus_space = format[i];
	else if ((format[i] == ' ') && (list->plus_space == '.'))
		list->plus_space = format[i];
	else if (format[i] == '-')
		list->minus_null = format[i];
	else if (format[i] == '0')
	{
		if (list->point == '.' && list->accuracy != '.')
		{
			if (list->minus_null == '.')
				list->minus_null = format[i];
		}
		else if (list->point == '.' && list->accuracy == '.')
			list->accuracy = 0;
		else if (list->point != '.' && list->accuracy != '.')
		{
			if (list->minus_null == '.')
				list->minus_null = format[i];
		}
	}
	else if (format[i] == '#')
		list->hash = format[i];
}

int		rem_width_accuracy(const char *format, va_list arg, int i, t_data *list)
{
	if (format[i])
	{
		if (list->point == '0')
		{
			if (format[i] == '*')
				list->width = va_arg(arg, int);
			else if (ft_isdigit(format[i]))
				i = ft_take_digit(format, i, list);
			else if (format[i] == '.')
				list->point = format[i];
		}
		else if (list->point == '.')
		{
			if (format[i] == '*')
				list->accuracy = va_arg(arg, int);
			else if (ft_isdigit(format[i]))
				i = ft_take_digit(format, i, list);
		}
	}
	return (i);
}

int		rem_length(const char *format, int i, t_data *list)
{
	if (format[i])
	{
		if (list->length == 0)
		{
			if (format[i] == 'L')
				list->length = 1;
			else if (format[i] == 'l')
				i = ft_l(format, i, list);
			else if (format[i] == 'h')
				i = ft_h(format, i, list);
		}
		else if ((format[i] == 'l' && list->length == 1) || list->length == 3 ||
			list->length == 5)
			list->length = 4;
	}
	return (i);
}

void	rem_type(const char *format, int i, t_data *list)
{
	if (format[i] && (list->type == '.'))
		list->type = format[i];
}
