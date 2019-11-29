/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:25 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/29 19:20:13 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_oktotorp(t_data *list, char *tmp)
{
	char			*ret;

	ret = NULL;
	ft_clean_counts(list);
	if (list->hash == '.')
		ret = ft_strdup(tmp);
	else if (list->hash == '#')
	{
		if (list->tmp > list->len)
			ret = ft_strdup(tmp);
		else if (list->tmp <= list->len)
			ret = ft_strjoin("0", tmp);
	}
	ft_clean_s(tmp);
	return (ret);
}

char				*ft_accuracy_o(t_data *list, char *tmp)
{
	char			*ret;

	ret = NULL;
	ft_clean_counts(list);
	if (list->accuracy >= list->len)
	{
		list->tmp = list->accuracy;
		ret = (char*)malloc(sizeof(char) * list->accuracy + 2);
		if (tmp[list->i] == '-')
		{
			ret[list->i++] = '-';
			list->len--;
			list->j++;
		}
		while (list->accuracy-- > list->len)
			ret[list->i++] = '0';
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i] = '\0';
	}
	else if (list->accuracy < list->len)
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

char					*ft_conversion_o(long long int value, int base)
{
	char				*str;
	short				size;
	char				*tab;
	unsigned long long	tmp;

	size = 1;
	tab = "01234567";
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

void	ft_o(t_data *list, va_list arg)
{
	long long int		o;
	char				*tmp;

	o = 0;
	tmp = NULL;
	list->len = 0;
	o = va_arg(arg, long long int);
	tmp = ft_conversion_o(o, 8);
	list->len = ft_strlen(tmp);
	tmp = ft_accuracy_o(list, tmp);
	tmp = ft_oktotorp(list, tmp);
	ft_write_and_clean_s(list, tmp);
}
