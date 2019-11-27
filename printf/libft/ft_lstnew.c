/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:27:20 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/24 13:43:03 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		newlist->next = NULL;
	}
	else
	{
		if (!(newlist->content = malloc(sizeof(content) * content_size)))
		{
			free(newlist);
			return (NULL);
		}
		newlist->content = ft_memcpy(newlist->content, content,
				content_size);
		newlist->content_size = content_size;
		newlist->next = NULL;
	}
	return (newlist);
}
