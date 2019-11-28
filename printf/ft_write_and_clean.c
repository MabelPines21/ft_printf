/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_and_clean.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:43:06 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/28 17:39:20 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_clean_list(t_data *list)
{
	list->percent = '.';
	list->plus_space = '.';
	list->minus_null = '.';
	list->hash = '.';
	list->width = 0;
	list->accuracy = 0;
	list->length = 0;
	list->type = '.';
	list->point = '0';
	list->ret = 0;
	list->len = 0;
	list->count = 0;
}

void		ft_clean_all(t_data *list)
{
	free(list);
	list = NULL;
}

void		ft_clean_s(char *s)
{
	if (s && *s)
	{
		free(s);
		s = NULL;
	}
}

void		ft_write_and_clean_s(t_data *list, char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		write(1, &s[i++], 1);
		list->ret++;
	}
	ft_clean_s(s);
}
