/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:58:37 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:38:37 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_dup_arg(t_list *stacka)
{
	t_list	*stackb;

	while (stacka)
	{
		stackb = stacka->next;
		while (stackb)
		{
			if (stacka->content == stackb->content)
				return (0);
			stackb = stackb->next;
		}
		stacka = stacka->next;
	}
	return (1);
}

int	is_sorted_arg(t_list *stacka)
{
	while (stacka->next != NULL)
	{
		if ((stacka->content) > (stacka->next->content))
			return (0);
		stacka = stacka->next;
	}
	return (1);
}
