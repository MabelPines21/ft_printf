/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:50:51 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/29 19:19:10 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

/*length
** 1 = l;
** 2 = h;
** 3 = L;
** 4 = ll;
** 5 = hh;
*/

typedef struct	s_data
{
	char		percent;
	char		plus_space;
	char		minus_null;
	char		hash;
	int			width;
	int			accuracy;
	char		point;
	int			length;
	char		type;
	int			ret;
	int			len;
	int			i;
	int			j;
	int			tmp;
}				t_data;

int		main();
int		ft_printf(const char *format, ...);
void	ft_clean_list(t_data *list);
void	ft_clean_all(t_data *list);
void	ft_clean_s(char *s);
void	rem_flag(const char *format, int i, t_data *list);
int		rem_width_accuracy(const char *format, va_list arg, int i,
			t_data *list);
int		rem_length(const char *format, int i, t_data *list);
void	rem_type(const char *format, int i, t_data *list);
int		ft_take_digit(const char *format, int i, t_data *list);
int		ft_l(const char *format, int i, t_data *list);
int		ft_h(const char *format, int i, t_data *list);
void	ft_allocation(t_data *list, va_list arg);
int     ft_precent(const char *format, va_list arg, t_data *list, int i);
int		ft_f(t_data *list, va_list arg);
void	ft_c(t_data *list, va_list arg);
void	ft_d_i(t_data *list, va_list arg);
void	ft_o(t_data *list, va_list arg);
void	ft_p(t_data *list, va_list arg);
void	ft_s(t_data *list, va_list arg);
int		ft_u(t_data *list, va_list arg);
int		ft_x_X(t_data *list, va_list arg);
int		ft_procent(t_data *list, int i);
void	ft_before(t_data *list, char *s, char *str, int i);
void	ft_width_s(t_data *list);
void	ft_write_and_clean_s(t_data *list, char *s);
void	ft_only_width(t_data *list, char *s, char *str, int i);
void	ft_width_d(t_data *list, char *tmp);
void	ft_clean_counts(t_data *list);



#endif
