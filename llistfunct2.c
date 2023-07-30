/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistfunct2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:55:14 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:30:47 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_index(t_list *stackdest, int pushnbr)
{
	t_list	*tmp;
	int		i;

	tmp = stackdest;
	i = 0;
	while (tmp)
	{
		if (tmp->content == pushnbr)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	ft_find_place(t_list *stackdest, int pushnbr)
{
	int		max;
	int		min;
	int		i;
	t_list	*tmp;

	max = maxcontent(stackdest);
	min = mincontent(stackdest);
	i = 1;
	if (pushnbr > max || pushnbr < min)
		i = ft_find_index(stackdest, maxcontent(stackdest));
	else if (pushnbr > stackdest->content
		&& pushnbr < ft_lstlast(stackdest)->content)
		i = 0;
	else
	{
		tmp = stackdest->next;
		while ((tmp && stackdest)
			&& (pushnbr > stackdest->content || pushnbr < tmp->content))
		{
			i++;
			stackdest = stackdest->next;
			tmp = stackdest->next;
		}
	}
	return (i);
}

int	ft_find_place_in_a(t_list *stackdest, int pushnbr)
{
	int		max;
	int		min;
	int		i;
	t_list	*tmp;

	max = maxcontent(stackdest);
	min = mincontent(stackdest);
	i = 1;
	if (pushnbr > max || pushnbr < min)
		i = ft_find_index(stackdest, mincontent(stackdest));
	else if (pushnbr < stackdest->content
		&& pushnbr > ft_lstlast(stackdest)->content)
		i = 0;
	else
	{
		tmp = stackdest->next;
		while ((tmp && stackdest)
			&& (pushnbr < stackdest->content || pushnbr > tmp->content))
		{
			i++;
			stackdest = stackdest->next;
			tmp = stackdest->next;
		}
	}
	return (i);
}
