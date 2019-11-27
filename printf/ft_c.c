/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:00:29 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/19 14:45:26 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_yes_w(char *s, t_data *list, va_list arg)
{
	int i;

	i = 0;
	list->width -= 1;
	s = (char*)malloc(sizeof(char) * (list->width + 2));
	if (list->minus_null == '-')
	{
		s[i++] = va_arg(arg, int);
		while (list->width-- != 0)
			s[i++] = ' ';
	}
	else if (list->minus_null != '-')
	{
		while (list->width-- != 0)
			s[i++] = ' ';
		s[i++] = va_arg(arg, int);
	}
	s[i] = '\0';
	ft_write_and_clean_s(list, s);
}

void		ft_c(t_data *list, va_list arg)
{
	int		j;
	char	*s;

	s = NULL;
	j = 0;
	if (list->width == 0)
	{
		s = (char*)malloc(sizeof(char) * 2);
		s[j++] = va_arg(arg, int);
		s[j] = '\0';
		ft_write_and_clean_s(list, s);
	}
	else if (list->width != 0)
		ft_yes_w(s, list, arg);
}
