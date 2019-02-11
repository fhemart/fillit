/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:01:55 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/28 11:15:32 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t				ft_getindex(unsigned short pos, size_t i)
{
	int				value;

	value = 32 - (pos % 32 + ((i - 15) * -1));
	value = value + ((((i - 15) * -1) / 4) * 4);
	return (value);
}

t_grid				*ft_getline(unsigned short pos, t_grid *gridline)
{
	t_grid			*line;
	size_t			nline;

	line = gridline;
	nline = 0;
	while (pos / 32 != nline)
	{
		line = line->next;
		nline++;
	}
	return (line);
}

void				ft_resetgrid(t_grid *head)
{
	t_grid			*cursor;

	cursor = head->next;
	while (cursor != head)
	{
		cursor->val = 0;
		cursor = cursor->next;
	}
}

int					checkempty(size_t size, t_grid *head)
{
	int				empty;
	int				i;
	int				j;
	t_grid			*cursor;

	empty = 0;
	i = 31;
	j = 0;
	cursor = head->next;
	while (j < (int)size)
	{
		while (i >= 32 - (int)size)
		{
			if ((cursor->val & (1 << i)) == 0)
				empty++;
			i--;
		}
		i = 31;
		cursor = cursor->next;
		j++;
	}
	return (empty);
}

int					leftblock(t_listc *current, t_listc *head)
{
	int				left;
	t_listc			*cursor;

	cursor = current->next;
	left = 0;
	if (current == head)
		return (0);
	while (current != head)
	{
		left++;
		current = current->next;
	}
	return (left);
}
