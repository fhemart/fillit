/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:15:33 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 07:41:55 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char *s, char c)
{
	int			data[(s) ? ft_strlen(s) + 1 : 1];
	char		**tab;
	int			i;
	int			j;
	int			y;

	i = 1;
	j = 0;
	y = 0;
	if (s && c)
	{
		ft_strwind(s, c, data);
		if (!(tab = malloc(sizeof(char *) * (data[0] + 1))))
			return (NULL);
		while (i <= data[0] * 2)
		{
			if (!(tab[j] = ft_strsub(s, data[i], (data[i + 1] + 1) - data[i])))
				return (NULL);
			i = i + 2;
			j++;
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
