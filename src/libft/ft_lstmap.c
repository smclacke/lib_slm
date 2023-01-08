/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 14:21:43 by smclacke      #+#    #+#                 */
/*   Updated: 2022/11/24 15:46:40 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<sys/queue.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*tmp;
	t_list	*link;
	t_list	*list;

	if (!f || !del || !lst)
		return (0);
	list = 0;
	while (lst)
	{
		tmp = f(lst->content);
		link = ft_lstnew(tmp);
		if (!link)
		{
			ft_lstclear(&link, (del));
			del(tmp);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&list, link);
	}
	return (list);
}
