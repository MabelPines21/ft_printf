/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:15 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/29 19:23:12 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_plus_space(t_data *list, char *tmp)
{
	char			*ret;
	int				len;

	ft_clean_counts(list);
	len = 0;
	ret = NULL;
	len = ft_strlen(tmp);
	if (list->plus_space == '.' || tmp[0] == '-')
		ret = ft_strdup(tmp);
	else if (list->plus_space != '.' && tmp[0] != '-')
	{
		ret = (char *)malloc(sizeof(char) * len + 2);
		ret[list->i++] = list->plus_space;
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i] = '\0';
	}
	ft_clean_s(tmp);
	ft_width_d(list, ret);
}

char				*ft_accuracy(t_data *list, char *tmp)
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

char				*ft_conversion_d(long long int n)
{
	int				i;
	char			*res;
	long			a;

	i = 1;
	a = n;
	if (n < 0)
		i++;
	while ((n = n / 10) != 0)
		i++;
	if ((res = ft_strnew(i)))
	{
		(a == 0) ? (res[0] = '0') : 0;
		if (a < 0)
		{
			res[0] = '-';
			a = a * (-1);
		}
		while (a != 0)
		{
			res[--i] = a % 10 + '0';
			a = a / 10;
		}
	}
	return (res);
}

long long			ft_length_d(t_data *list, va_list arg)
{
	long long int	res;

	res = 0;
	if (list->length == 4)
		res = va_arg(arg, long long int);
	else if (list->length == 2)
		res = va_arg(arg, long int);
	else
		res = va_arg(arg, int);
	return (res);
}

void				ft_d_i(t_data *list, va_list arg)
{
	long long int	value;
	char			*tmp;

	value = 0;
	tmp = NULL;
	value = ft_length_d(list, arg);
	tmp = ft_conversion_d(value);
	list->len = ft_strlen(tmp);
	tmp = ft_accuracy(list, tmp);
	ft_plus_space(list, tmp);
}
