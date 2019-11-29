/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:16:13 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/24 13:40:22 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **ukaz)
{
	t_list	*tmp;

	if (*ukaz == NULL)
		return ;
	while (*ukaz)
	{
		tmp = (*ukaz)->next;
		free((*ukaz)->content);
		free(*ukaz);
		*ukaz = NULL;
		*ukaz = tmp;
	}
	free(*ukaz);
	*ukaz = NULL;
}
