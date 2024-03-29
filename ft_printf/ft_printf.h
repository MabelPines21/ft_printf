/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:50:51 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/12 15:26:28 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/*
** 1 = l;2 = h;3 = L;4 = ll;5 = hh;
*/
typedef struct				s_data
{
	char					percent;
	char					plus_space;
	char					minus_null;
	char					hash;
	char					point;
	char					type;
	long long int			width;
	long long int			accuracy;
	int						length;
	long long int			ret;
	long long int			len;
	long long int			i;
	long long int			j;
	long long int			tmp;
	int						nol;
}							t_data;

int							main();
int							ft_printf(const char *format, ...);
int							rem_width_accuracy(const char *format, va_list arg,
							int i, t_data *list);
int							rem_length(const char *format, int i, t_data *list);
int							ft_take_digit(const char *format, int i,
							t_data *list);
int							ft_l(const char *format, int i, t_data *list);
int							ft_h(const char *format, int i, t_data *list);
int							ft_procent(t_data *list, int i);
int							ft_precent(const char *format, va_list arg,
							t_data *list, int i);
void						ft_allocation(t_data *list, va_list arg);
void						rem_type(const char *format, int i, t_data *list);
void						rem_flag(const char *format, int i, t_data *list);
void						ft_f(t_data *list, va_list arg);
void						ft_c(t_data *list, va_list arg);
void						ft_d_i(t_data *list, va_list arg);
void						ft_o(t_data *list, va_list arg);
void						ft_p(t_data *list, va_list arg);
void						ft_s(t_data *list, va_list arg);
void						ft_u(t_data *list, va_list arg);
void						ft_x(t_data *list, va_list arg);
void						ft_before(t_data *list, char *s, char *str);
void						ft_width_s(t_data *list);
void						ft_write_and_clean_s(t_data *list, char *s);
void						ft_only_width(t_data *list, char *s, char *str);
void						ft_width_d(t_data *list, char *tmp);
void						ft_clean_counts(t_data *list);
void						ft_clean_list(t_data *list);
void						ft_clean_all(t_data *list);
void						ft_clean_s(char *s);
char						*ft_strdup(const char *str);
char						*ft_strjoin(char *s1, char *s2);
int							ft_isdigit(int c);
int							ft_strlen(const char *str);
char						*ft_strnew(size_t size);
void						ft_putchar(char c);
char						*ft_strcat(char *destination, const char *append);
char						*ft_strcpy(char *str1, char *str2);
void						*ft_memset(void *destination, int c, size_t n);
void						ft_null(t_data *list, char *str);
int							ft_isalpha(int c);
char						*ft_accuracy_o(t_data *list, char *tmp, char *ret);
void						ft_null_s(t_data *list, char *str);
void						ft_width_null_s(t_data *list, char *str, char *tmp);
int							ft_help_i(t_data *list, int value);
void						ft_list_null(t_data *list, char *s, char *str);
void						ft_list_null2(t_data *list, char *s, char *str);
void						ft_list_null3(t_data *list, char *s, char *str);
char						*ft_strchr(const char *str, int ch);

#endif
