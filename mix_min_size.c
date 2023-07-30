/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_min_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:58:52 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 17:17:43 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	maxcontent(t_list *stackA)
{
	int		max;
	t_list	*temp;

	temp = stackA;
	max = temp->content;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}

int	mincontent(t_list *stackA)
{
	int		min;
	t_list	*temp;

	temp = stackA;
	min = temp->content;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

int	ft_stacksize(t_list *stackA)
{
	int	i;

	i = 0;
	while (stackA != NULL)
	{
		stackA = stackA->next;
		i++;
	}
	return (i);
}
