/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:59:04 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:25:54 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_list **stackA, char c)
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
	if (c == 'm')
		write (1, "ra\n", 3);
}

void	rb(t_list **stackA, char c)
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
	if (c == 'm')
		write (1, "rb\n", 3);
}

void	rrb(t_list **stackA, char c)
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
	if (c == 'm')
		write (1, "rrb\n", 4);
}

void	ss(t_list **stackA, t_list **stackB, char c)
{
	if (!(*stackA) || !(*stackA)->next)
		return ;
	sa(stackA, c);
	sb(stackB, c);
	if (c == 'm')
		write (1, "ss\n", 3);
}
