/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistfunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:58:59 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:27:27 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_end(t_list **lst, int content)
{
	t_list	*temp;

	temp = *lst;
	if (!(*lst))
	{
		*lst = ft_lstnew(content);
		return ;
	}
	while (temp->next != NULL)
		temp = temp -> next;
	temp->next = ft_lstnew(content);
}

void	ft_lstadd_head(t_list **lst, int content)
{
	t_list	*temp;

	temp = ft_lstnew(content);
	if (!*lst)
	{
		*lst = temp;
		return ;
	}
	temp->next = *lst;
	*lst = temp;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstlast_second(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
