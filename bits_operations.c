/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:11:03 by dhigelin          #+#    #+#             */
/*   Updated: 2017/11/28 11:16:36 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_switchbit(t_listc *head)
{
	unsigned short	maskl;
	unsigned short	masku;
	t_listc			*tmp;

	tmp = head->next;
	maskl = (short)34952;
	masku = (short)61440;
	while (tmp != head)
	{
		while ((tmp->val & maskl) == 0 && (tmp->val & maskl) != maskl)
			tmp->val = tmp->val << 1;
		while ((tmp->val & masku) == 0 && (tmp->val & masku) != masku)
			tmp->val = tmp->val << 4;
		tmp = tmp->next;
	}
}

size_t				ft_cmpbit(t_listc *block, t_grid *line,
						unsigned short pos, size_t bit)
{
	if ((block->val & (1 << (bit - 1))) != 0 && (unsigned long)(line->val &
		(1 << (unsigned int)(ft_getindex(pos, bit - 1) - 1))) != 0)
		return (0);
	return (1);
}

size_t				ft_setbit(t_listc *block, t_grid *line,
						unsigned short pos, size_t bit)
{
	if ((block->val & (1 << (bit - 1))) != 0)
		line->val = line->val | (1 <<
			(unsigned int)(ft_getindex(pos, bit - 1) - 1));
	return (1);
}

size_t				ft_unsetbit(t_listc *block, t_grid *line,
						unsigned short pos, size_t bit)
{
	if ((block->val & (1 << (bit - 1))) != 0)
		line->val = line->val ^ (1 <<
			(unsigned int)(ft_getindex(pos, bit - 1) - 1));
	return (1);
}

size_t				ft_foreachbit(t_grid *head, t_listc *block,
						unsigned short pos, size_t (*f)
							(t_listc *, t_grid *, unsigned short, size_t))
{
	t_grid			*line;
	size_t			l;
	size_t			nbit;

	l = 0;
	nbit = 16;
	line = head->next;
	line = ft_getline(pos, line);
	while (nbit >= 1)
	{
		if ((*f)(block, line, pos, nbit) == 0)
			return (0);
		nbit--;
		l++;
		if (l == 4)
		{
			line = line->next;
			l = 0;
		}
	}
	return (1);
}
