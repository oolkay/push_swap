/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:59:02 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:26:39 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_list **stackA, t_list**stackB, char c)
{
	t_list	*lastnode;
	t_list	*secondlastnode;

	if (!(*stackA) || !(*stackA)->next)
		return ;
	lastnode = ft_lstlast(*stackA);
	secondlastnode = ft_lstlast_second(*stackA);
	lastnode->next = *stackA;
	*stackA = lastnode;
	secondlastnode->next = NULL;
	if (!(*stackB) || !(*stackB)->next)
		return ;
	lastnode = ft_lstlast(*stackB);
	secondlastnode = ft_lstlast_second(*stackB);
	lastnode->next = *stackB;
	*stackB = lastnode;
	secondlastnode->next = NULL;
	if (c == 'm')
		write (1, "rrr\n", 4);
}

void	rr(t_list **stackA, t_list **stackB, char c)
{
	t_list	*lastnode;
	t_list	*head;

	if (!(*stackA) || !(*stackA)->next)
		return ;
	lastnode = ft_lstlast(*stackA);
	head = *stackA;
	*stackA = (*stackA)->next;
	lastnode->next = head;
	head->next = NULL;
	if (!(*stackB) || !(*stackB)->next)
		return ;
	lastnode = ft_lstlast(*stackB);
	head = *stackB;
	*stackB = (*stackB)->next;
	lastnode->next = head;
	head->next = NULL;
	if (c == 'm')
		write (1, "rr\n", 3);
}
