/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:14:33 by dhigelin          #+#    #+#             */
/*   Updated: 2017/11/28 11:16:18 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					convert_bit_to_pos(size_t size, size_t block_pos,
		int bit_pos)
{
	int				i;
	int				bit_line;

	i = (block_pos / 32) * size + (block_pos % 32);
	bit_line = bit_pos / 4;
	i = i + bit_pos % 4;
	i = i + bit_line * size;
	return (i);
}

char				*ft_stkresult(t_listc *blockhead, size_t len)
{
	char			*s;
	t_listc			*block;
	int				l;
	size_t			c;

	block = blockhead->next;
	c = 0;
	if (!(s = malloc(sizeof(char) * (len * len) + 1)))
		return (NULL);
	ft_memset((void*)s, '.', (len * len));
	s[(len * len)] = '\0';
	while (block != blockhead)
	{
		l = 16;
		while (l--)
		{
			if ((block->val & (1 << (l))) != 0)
				s[convert_bit_to_pos(len, block->pos, (l - 15) * -1)] = 65 + c;
		}
		c++;
		block = block->next;
	}
	return (s);
}
