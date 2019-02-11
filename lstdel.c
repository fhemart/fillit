/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 09:37:55 by dhigelin          #+#    #+#             */
/*   Updated: 2017/11/28 09:39:25 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lstcdel(t_listc *head)
{
	t_listc	*tmp;
	t_listc	*next;

	tmp = head->next;
	while (tmp != head)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void		ft_lstcdelhead(t_listc **head)
{
	ft_lstcdel(*head);
	free(*head);
	*head = NULL;
}

void		ft_gridel(t_grid *head)
{
	t_grid	*tmp;
	t_grid	*next;

	tmp = head->next;
	while (tmp != head)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void		ft_gridelhead(t_grid **head)
{
	ft_gridel(*head);
	free(*head);
	*head = NULL;
}
