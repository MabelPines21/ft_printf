/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:43:25 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/02 17:01:37 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_null_d(t_data *list, char *tmp, char *res)
{
	ft_clean_counts(list);
	if (list->tmp != '.')
	{
		while (list->width-- != 0)
			res[list->i++] = ' ';
		while (tmp[list->j])
			res[list->i++] = tmp[list->j++];
	}
	else
	{
		if (tmp[list->i] == '-' || tmp[list->i] == '+')
			res[list->i++] = tmp[list->j++];
		while (list->width-- != 0)
			res[list->i++] = '0';
		while (tmp[list->j])
			res[list->i++] = tmp[list->j++];
	}
	res[list->i] = '\0';
	ft_clean_s(tmp);
	ft_write_and_clean_s(list, res);
}

void		ft_minus_d(t_data *list, char *tmp, char *res)
{
	list->i = 0;
	list->j = 0;
	if (list->minus_null == '-')
	{
		while (tmp[list->j])
			res[list->i++] = tmp[list->j++];
		while (list->width-- != 0)
			res[list->i++] = ' ';
		res[list->i] = '\0';
		ft_clean_s(tmp);
		ft_write_and_clean_s(list, res);
	}
}

void		ft_point_d(t_data *list, char *tmp, char *res)
{
	ft_clean_counts(list);
	if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			res[list->i++] = ' ';
		while (tmp[list->j])
			res[list->i++] = tmp[list->j++];
		res[list->i] = '\0';
		ft_clean_s(tmp);
		ft_write_and_clean_s(list, res);
	}
}

void		ft_width_d(t_data *list, char *tmp)
{
	char	*res;

	res = NULL;
	list->len = ft_strlen(tmp);
	ft_clean_counts(list);
	if (list->width <= list->len)
		ft_write_and_clean_s(list, tmp);
	else if (list->width > list->len)
	{
		res = (char*)malloc(sizeof(char) * list->width + 1);
		list->width = list->width - list->len;
		if (list->minus_null == '.')
			ft_point_d(list, tmp, res);
		else if (list->minus_null == '-')
			ft_minus_d(list, tmp, res);
		else if (list->minus_null == '0')
			ft_null_d(list, tmp, res);
	}
}
