/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfunct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:59:09 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:21:27 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_list(t_list **stackA, char **argv, int indx)
{
	int	temp;

	while (argv[indx])
	{
		temp = ft_atoi(argv[indx]);
		ft_lstadd_end(stackA, temp);
		indx++;
	}
}

void	init_stack_2(t_list **stackA, char **argv)
{
	char	**tmp;

	if (argv[1][0] == '\0')
		ft_error();
	tmp = ft_split(argv[1], ' ');
	add_list (stackA, tmp, 0);
	free(tmp);
}

void	init_stack_1(t_list **stackA, int argc, char **argv)
{
	int	len;

	len = 1;
	if (argc > 2)
		add_list(stackA, argv, 1);
	else if (argc == 2)
		init_stack_2(stackA, argv);
	else
		exit(1);
}
