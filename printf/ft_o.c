/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:25 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/28 15:58:25 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_o(t_data *list, va_list arg)
{
	int	o;
	
	o = 0;
	o = va_arg(arg, int);
	list->len = 0;
	printf("%o\n", o);
}
