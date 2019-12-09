/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <elee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:46:48 by sferreir          #+#    #+#             */
/*   Updated: 2019/11/26 14:33:40 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		hash_count(char *src)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (src[i] && src[i] != '\n' && src[i] != '#' && src[i] != '.')
			return (0);
		if (src[i] == '\n' && ((i + 1) % 5) != 0)
			return (0);
		if (src[i] == '#')
			count++;
		i++;
	}
	if (!src[i] || src[i] != '\n')
		return (0);
	return (count);
}

int		adjac_count(char *src)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (src[i] == '#')
		{
			if (i + 1 <= 18 && src[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && src[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && src[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && src[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int		valid(char *src, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (hash_count(src + i) != 4)
			return (0);
		if (adjac_count(src + i) != 6 && adjac_count(src + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
