/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:15 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/28 18:26:15 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_plus_space(t_data *list, char *tmp)
{
	char			*ret;
	int				j;
	int				len;

	list->count = 0;
	j = 0;
	len = 0;
	ret = NULL;
	len = ft_strlen(tmp);
	if (list->plus_space == '.' || tmp[0] == '-')
		ret = ft_strdup(tmp);
	else if (list->plus_space != '.' && tmp[0] != '-')
	{
		ret = (char *)malloc(sizeof(char) * len + 2);
		ret[list->count++] = list->plus_space;
		while (tmp[j])
			ret[list->count++] = tmp[j++];
		ret[list->count] = '\0';
	}
	ft_clean_s(tmp);
	return (ret);
}

char				*ft_accuracy(t_data *list, char *tmp)
{
	int				j;
	char			*ret;

	list->count = 0;
	j = 0;
	ret = NULL;
	if (list->accuracy >= list->len)
	{
		ret = (char*)malloc(sizeof(char) * list->accuracy + 2);
		if (tmp[list->count] == '-')
		{
			ret[list->count++] = '-';
			list->len--;
			j++;
		}
		while (list->accuracy-- > list->len)
			ret[list->count++] = '0';
		while (tmp[j])
			ret[list->count++] = tmp[j++];
		ret[list->count] = '\0';
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
	char			*i;
	char			*res;
	char			*tmp;

	value = 0;
	tmp = NULL;
	i = NULL;
	res = NULL;
	value = ft_length_d(list, arg);
	i = ft_conversion_d(value);
	list->len = ft_strlen(i);
	res = ft_accuracy(list, i);
	tmp = ft_plus_space(list, res);
	ft_write_and_clean_s(list, tmp);
	//ft_flags_d(list, i);
}
