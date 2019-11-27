/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:04:51 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/21 16:44:34 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_allocation(t_data *list, va_list arg)
{
	if (list->type == 'c')
		ft_c(list, arg);
	else if (list->type == 's')
		ft_s(list, arg);
	else if (list->type == 'p')
		ft_p(list, arg);
	else if (list->type == 'd' || list->type == 'i')
		ft_d_i(list, arg);
	/*else if (list->type == 'o')
		ft_o(list, arg);
	else if (list->type == 'u')
		ft_u(list, arg);
	else if (list->type == 'x' || list->type == 'X')
		ft_x_X(list, arg);
	else if (list->type == 'f')
		ft_f(list, arg);
*/}
