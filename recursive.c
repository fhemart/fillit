/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:55:47 by dhigelin          #+#    #+#             */
/*   Updated: 2017/11/28 12:15:59 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			movepos(size_t *current_pos, size_t size)
{
	if (*current_pos + 1 < (((*current_pos / 32) * 32) + size))
	{
		*current_pos += 1;
		return (1);
	}
	else
	{
		if (*current_pos == ((size - 1) * 32) + size - 1)
			return (0);
		else
		{
			*current_pos = ((*current_pos / 32) + 1) * 32;
			return (1);
		}
	}
}

int			isok(t_listc *block, t_grid *head, size_t pos, size_t size)
{
	if (!((int)(block->width + (pos % 32)) <= (int)size))
		return (0);
	if (!((int)(block->height + (pos / 32)) <= (int)size))
		return (0);
	if (ft_foreachbit(head, block, pos, (&ft_cmpbit)) == 0)
		return (0);
	return (1);
}

int			isempty(t_grid *head, size_t pos)
{
	t_grid	*line;

	line = ft_getline(pos, head);
	if ((unsigned long)(line->val & (1 << (unsigned int)
			((pos % 32) * -1))) != 0)
		return (0);
	return (1);
}

int			rec(t_listc *blockhead, t_listc *block, t_grid *head, size_t size)
{
	size_t	i;

	i = 0;
	if (block == blockhead)
		return (1);
	if (isempty(head, block->pos) != 1)
	{
		movepos(&(block->pos), size);
		return (rec(blockhead, block, head, size));
	}
	while (block->pos % 32 < (size * size) - 1 && i < size)
	{
		if (isok(block, head, block->pos, size) == 1)
		{
			ft_foreachbit(head, block, block->pos, (&ft_setbit));
			if (rec(blockhead, block->next, head, size) == 1)
				return (1);
		}
		if (block->pos % 32 == size - 1)
			i++;
		movepos(&(block->pos), size);
	}
	ft_foreachbit(head, block->prev, block->prev->pos, (&ft_unsetbit));
	block->pos = 0;
	return (0);
}
