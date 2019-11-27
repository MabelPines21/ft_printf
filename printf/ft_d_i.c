/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:15 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/27 19:22:33 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**ft_ft_width_s(t_data *list, char *s)
*/

char		*ft_width_accuracy_d(t_data *list, char *str)
{
	
}

char		*ft_plus_space(t_data *list, char *str)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = NULL;
	tmp = NULL;
	if (list->plus_space != '.')
	{
		if (str[i] != '-')
		{
			list->len++;
			ret = (char*)malloc(sizeof(char) * list->len + 1);
			ret[i++] = list->plus_space;
			tmp = ret;
			ft_clean_s(ret);
			ret = ft_strjoin(tmp, str);
		}
		else if (str[i] == '-')
			ret = ft_strdup(str);
	}
	else if (list->plus_space == '.')
		ret = ft_strdup(str);
	return (ret);
}

char		*ft_flags_d(t_data *list, char *tmp)
{
	char	*fin;

	fin = NULL;
	fin = ft_plus_space(list, tmp);
	fin = ft_width_accuracy_d(list, tmp);
	return (fin);
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
	char			*ret;

	value = 0;
	ret = NULL;
	tmp = NULL;
	value = ft_length_d(list, arg);
	tmp = ft_conversion_d(value);
	list->len = ft_strlen(tmp);
	ret = ft_flags_d(list, tmp);
	ft_clean_s(tmp);
	ft_write_and_clean_s(list, ret);
}
