/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:46:01 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/28 09:36:42 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_printresult(size_t len, const char *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
		j++;
		if (j == len)
		{
			ft_putchar('\n');
			j = 0;
		}
	}
}
