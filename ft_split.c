/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:23:55 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 13:59:17 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	wordslen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

static int	wordsnbr(const char *str, char c)
{
	int		i;
	int		rvalue;

	i = 0;
	rvalue = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
			rvalue++;
		i++;
	}
	return (rvalue);
}

static char	*splitter(const char *s, char c)
{
	int		i;
	char	*resultstr;

	resultstr = (char *)malloc(sizeof(char) * (wordslen(s, c) + 1));
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		resultstr[i] = s[i];
		i++;
	}
	resultstr[i] = '\0';
	return (resultstr);
}

char	**ft_split(const char *s, char c)
{
	char	**spltdstr;
	int		i;
	int		j;
	int		wcount;

	wcount = wordsnbr(s, c);
	spltdstr = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!spltdstr)
		return (0);
	i = 0;
	j = 0;
	while (i < wcount)
	{
		while (s[j] == c)
			j++;
		spltdstr[i] = splitter(s + j, c);
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	spltdstr[i] = 0;
	return (spltdstr);
}
