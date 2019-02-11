/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:14:46 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/20 09:18:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lstcshow(t_listc *head)
{
	t_listc	*tmp;

	if (head)
	{
		tmp = head->next;
		while (tmp != head)
		{
			ft_putnbr(tmp->val);
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}

void		ft_gridshow(t_grid *head)
{
	t_grid	*tmp;

	if (head)
	{
		tmp = head->next;
		while (tmp != head)
		{
			ft_putlnbr(tmp->val);
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}
