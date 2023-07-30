/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:58:42 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 17:03:12 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*stacka;

	init_stack_1(&stacka, argc, argv);
	if (is_dup_arg(stacka) == 0)
	{
		ft_free(&stacka);
		ft_error();
	}
	if (is_sorted_arg(stacka) == 0)
		start_swap(&stacka);
	ft_free(&stacka);
	return (0);
}
