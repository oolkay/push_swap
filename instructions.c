/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:59:06 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:24:34 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **stackA, char c)
{
	int	temp;

	if (!(*stackA) || !(*stackA)->next)
		return ;
	temp = (*stackA)->content;
	(*stackA)->content = (*stackA)->next->content;
	(*stackA)->next->content = temp;
	if (c == 'm')
		write (1, "sa\n", 3);
}

void	sb(t_list **stackB, char c)
{
	int	temp;

	if (!(*stackB) || !(*stackB)->next)
		return ;
	temp = (*stackB)->content;
	(*stackB)->content = (*stackB)->next->content;
	(*stackB)->next->content = temp;
	if (c == 'm')
		write (1, "sb\n", 3);
}

void	pa(t_list **stackdest, t_list **stacksrc, char c)
{
	t_list	*pushdest;

	if (!stacksrc)
		return ;
	if (!stackdest)
	{
		*stackdest = ft_lstnew((*stacksrc)->content);
		return ;
	}
	pushdest = *stacksrc;
	*stacksrc = (*stacksrc)->next;
	pushdest->next = *stackdest;
	(*stackdest) = pushdest;
	if (c == 'm')
		write (1, "pa\n", 3);
}

void	pb(t_list **stackdest, t_list **stacksrc, char c)
{
	t_list	*pushdest;

	if (!*stacksrc)
		return ;
	pushdest = *stacksrc;
	*stacksrc = (*stacksrc)->next;
	pushdest->next = *stackdest;
	(*stackdest) = pushdest;
	if (c == 'm')
		write (1, "pb\n", 3);
}

void	rra(t_list **stackA, char c)
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
		write (1, "rra\n", 4);
}
