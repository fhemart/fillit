/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 01:54:13 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/27 23:09:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long		ft_pow(unsigned long nb, unsigned long pow)
{
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (nb);
	else
		nb = nb * ft_pow(nb, pow - 1);
	return (nb);
}

void				ft_stkdata(char *str, t_listc *head)
{
	size_t			i;
	int				pos;
	unsigned long	value;

	i = 0;
	value = 0;
	pos = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '1')
			value = value + (ft_pow(2, pos));
		i++;
		pos--;
	}
	ft_lstcpushback(head, value / 2);
}

void				ft_parse(char *buff, t_listc *head)
{
	size_t			i;
	size_t			j;
	char			str[16];

	i = 0;
	j = 0;
	while (buff[i + 1])
	{
		if (buff[i] == '.')
			str[j++] = '0';
		if (buff[i] == '#')
			str[j++] = '1';
		if (buff[i] == '\n' && buff[i + 1] == '\n')
		{
			str[j] = '\0';
			j = 0;
			ft_stkdata(str, head);
		}
		i++;
	}
	str[j] = '\0';
	ft_stkdata(str, head);
}
