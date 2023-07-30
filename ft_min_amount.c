/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_amount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:55:09 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 16:57:25 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_min_amount(t_list *stacksrc, t_list *stackdest, char ch)
{
	int		min_amount;
	t_list	*tmp;

	tmp = stacksrc;
	min_amount = ft_case_rrarrb(stacksrc, stackdest, tmp->content, ch);
	while (tmp)
	{
		if (ft_case_rrarb(stacksrc, stackdest, tmp->content, ch) < min_amount)
			min_amount = ft_case_rrarb(stacksrc, stackdest, tmp->content, ch);
		if (ft_case_rarb(stacksrc, stackdest, tmp->content, ch) < min_amount)
			min_amount = ft_case_rarb(stacksrc, stackdest, tmp->content, ch);
		if (ft_case_rrarrb(stacksrc, stackdest, tmp->content, ch) < min_amount)
			min_amount = ft_case_rrarrb(stacksrc, stackdest, tmp->content, ch);
		if (ft_case_rarrb(stacksrc, stackdest, tmp->content, ch) < min_amount)
			min_amount = ft_case_rarrb(stacksrc, stackdest, tmp->content, ch);
		tmp = tmp->next;
	}
	return (min_amount);
}
