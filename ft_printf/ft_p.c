/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:05 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/29 18:21:29 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_conversion_p(unsigned long long value, int base)
{
	char				*str;
	short				size;
	char				*tab;
	unsigned long long	tmp;

	size = 1;
	tab = "0123456789abcdef";
	tmp = value;
	while (tmp /= base)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size--] = tab[value % base];
		value /= base;
	}
	return (str);
}

void					ft_final_p(t_data *list, char *tmp, char *str, int i)
{
	int					j;

	j = 0;
	if (list->minus_null == '-')
	{
		str[i++] = '0';
		str[i++] = 'x';
		while (tmp[j])
			str[i++] = tmp[j++];
		while (list->width-- != 0)
			str[i++] = ' ';
	}
	if (list->minus_null != '-')
	{
		while (list->width-- != 0)
			str[i++] = ' ';
		str[i++] = '0';
		str[i++] = 'x';
		while (tmp[j])
			str[i++] = tmp[j++];
	}
	str[i] = '\0';
	ft_write_and_clean_s(list, str);
}

void					ft_width_p(t_data *list, char *tmp)
{
	char				*str;
	int					i;
	int					j;

	str = NULL;
	i = 0;
	j = 0;
	if (list->width > list->len)
	{
		str = (char *)malloc(sizeof(char) * list->width + 1);
		list->width = list->width - list->len;
		ft_final_p(list, tmp, str, i);
	}
	else if (list->width <= list->len)
	{
		str = (char *)malloc(sizeof(char) * list->len + 1);
		str[i++] = '0';
		str[i++] = 'x';
		while (tmp[j])
			str[i++] = tmp[j++];
		str[i] = '\0';
		ft_write_and_clean_s(list, str);
	}
}

void					ft_p(t_data *list, va_list arg)
{
	unsigned long long	p;
	char				*tmp;

	tmp = NULL;
	p = va_arg(arg, unsigned long long);
	tmp = ft_conversion_p(p, 16);
	list->len = (ft_strlen(tmp) + 2);
	ft_width_p(list, tmp);
	ft_clean_s(tmp);
}
