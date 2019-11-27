/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:55:20 by vaisha            #+#    #+#             */
/*   Updated: 2019/11/19 18:16:43 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

long long				ft_sign(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char					*ft_itoa_base_sig(long long int value, int base)
{
	char				*str;
	short				size;
	char				*tab;
	long long			tmp;

	size = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_sign(value % base)];
		size--;
		value /= base;
	}
	return (str);
}

char					*ft_itoa_base_unsig(long long int value, int base)
{
	char				*str;
	short				size;
	char				*tab;
	long long			tmp;

	size = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % base];
		size--;
		value /= base;
	}
	return (str);
}
