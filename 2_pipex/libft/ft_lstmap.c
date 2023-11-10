/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:52:55 by seojchoi          #+#    #+#             */
/*   Updated: 2023/03/19 16:21:17 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*newcont;

	new_lst = NULL;
	while (lst)
	{
		newcont = f(lst->content);
		node = ft_lstnew(newcont);
		if (node == 0)
		{
			del(newcont);
			ft_lstclear(&new_lst, del);
			break ;
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst -> next;
	}
	return (new_lst);
}
