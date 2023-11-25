/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:02:34 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/25 15:12:37 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*new_content;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		if (lst->content != NULL)
		{
			new_content = f(lst->content);
			new_node = ft_lstnew(new_content);
			if (new_node == NULL)
			{
				del(new_content);
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			ft_lstadd_back(&new_list, new_node);
		}
		lst = lst->next;
	}
	return (new_list);
}
