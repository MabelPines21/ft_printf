/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:42:43 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/28 15:55:49 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char		*ft_help_second(t_data *list, char *str, char *ret, int i)
{
	int j;

	j = 0;
	if (list->minus_null == '-')
	{
		
	}
	str[i] = '\0';
}

char		*ft_plus(t_data *list, char *str)
{
	char	*ret;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	ret = NULL;
	if (str[i] == '-')
	{
		ret = ft_strdup(str);
		return (ret);
	}
	if (list->plus_space == '.')
		ret = ft_strdup(str);
	else if (list->plus_space == '+')
	{
		ret = (char*)malloc(sizeof(char) * list->len + 2);
		ret[i++] = list->plus_space;
		tmp = ret;
		ft_clean_s(ret);
		ret = ft_strjoin(tmp, str);
	}
	return (ret);
}

char		*ft_space(t_data *list, char *str)
{
	char	*ret;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	ret = NULL;
	if (str[i] == '-')
	{
		ret = ft_strdup(str);
		return (ret);
	}
	if (list->width > (list->len + 1))
		
}

void		ft_flags_d(t_data *list, char *tmp)
{
	char	*fin;

	fin = NULL;
	if ((list->plus_space == '+') || (list->plus_space == '.'))
		fin = ft_plus(list, tmp);
	else if (list->plus_space == ' ')
		fin = ft_space(list, tmp);
	ft_clean_s(tmp);
	fin = ft_width_accuracy_d(list, fin);
	ft_write_and_clean_s(list, fin);
}*/
