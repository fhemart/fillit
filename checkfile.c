/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:08:56 by dhigelin          #+#    #+#             */
/*   Updated: 2017/11/27 20:21:37 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_file_length(int size)
{
	int		block_amount;

	block_amount = size / 20;
	block_amount -= block_amount / 20;
	if ((size - (block_amount - 1)) % 20 == 0)
		return (1);
	return (0);
}

int			check_block(char *str)
{
	int		i;
	int		j;
	int		symbols_counter;

	symbols_counter = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i * 5 + j] == '#')
				symbols_counter++;
			if (str[i * 5 + j] != '.' && str[i * 5 + j] != '#')
				return (0);
			j++;
		}
		if (str[i * 5 + j] && str[i * 5 + j] != '\n')
			return (0);
		i++;
	}
	if (symbols_counter != 4)
		return (0);
	return (1);
}

int			ft_filecheck(char *buff, size_t nblock)
{
	size_t	i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < nblock)
	{
		if (!check_block(buff + (i * 21)))
			return (0);
		if (!buff[i * 21 + 20])
			return (1);
		if (buff[i * 21 + 20] != '\n')
			return (0);
		i++;
	}
	return (0);
}
