/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:41:59 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/28 15:56:04 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char		*ft_first_d(t_data *list, char *str, char *ret)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	ft_width_s(list);
	if (list->minus_null == '-')
	{
		while (str[j] && list->accuracy-- != 0)
			ret[i++] = str[j++];
		while (list->width-- != 0)
			ret[i++] = ' ';
		ret[i] = '\0';
	}
	else if (list->minus_null != '-')
		ret = ft_next(list, str, ret);
	return (ret);
}

char		*ft_next(t_data *list, char *str, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (list->minus_null == '0')
	{
		while (list->width-- != 0)
			str[i++] = '0';
	}
	else if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			str[i++] = ' ';
	}
	while (str[j] && list->accuracy-- != 0)
		ret[i++] = str[j++];
	ret[i] = '\0';
	return (ret);
}

char		*ft_second_d(t_data *list, char *str, char *ret)
{
	char	*f;
	int		j;
	int		i;
	int		len;

	j = 0;
	i = 0;
	f = NULL;
	len = ft_strlen(ret);
	if (list->width > list->len)
	{
		f = (char *)malloc(sizeof(char) * len + 1);
		list->width = list->width - list->len;
		f = ft_help_second(list, str, ret, i);
		ft_clean_s(ret);
		return (f);
	}
	else if (list->width < list->len)
	{
		while (str[j])
			ret[i++] = str[j++];
		ret[i] = '\0';
		return (ret);
	}
}

char		*ft_third_d(t_data *list, char *str, char *ret)
{
	
}

char		*ft_width_accuracy_d(t_data *list, char *str)
{
	char	*pol;

	pol = NULL;
	if (str)
	{
		if ((list->width > list->len) || (list->width == list->len))
			pol = ((char *)malloc(sizeof(char) * (list->width + 1)));
		else if (list->width < list->len)
			pol = ((char *)malloc(sizeof(char) * (list->len + 1)));
	}
	if (list->width == 0 && list->accuracy == 0)
	{
		ft_clean_s(pol);
		return (str);
	}
	else if (list->width != 0 && list->accuracy != 0)
		pol = ft_first_d(list, str, pol);
	else if (list->width != 0 && list->accuracy == 0)
		pol = ft_second_d(list, str, pol);
	else if (list->width == 0 && list->accuracy != 0)
		pol = ft_third_d(list, str, pol);
	return (pol);
}*/
