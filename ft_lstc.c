/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 02:01:08 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/28 09:37:44 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_listc		*ft_lstcnew(void)
{
	t_listc	*head;

	if (!(head = malloc(sizeof(t_listc))))
		return (NULL);
	head->prev = head;
	head->next = head;
	return (head);
}

void		ft_lstcpushback(t_listc *head, unsigned short val)
{
	t_listc	*newlist;

	if (!head)
		return ;
	if (!(newlist = malloc(sizeof(t_listc))))
		return ;
	newlist->val = val;
	newlist->pos = 0;
	newlist->next = head;
	newlist->prev = head->prev;
	head->prev->next = newlist;
	head->prev = newlist;
}

void		ft_gridpushback(t_grid *head)
{
	t_grid	*newlist;

	if (!head)
		return ;
	if (!(newlist = malloc(sizeof(t_grid))))
		return ;
	newlist->val = 0;
	newlist->next = head;
	newlist->prev = head->prev;
	head->prev->next = newlist;
	head->prev = newlist;
}

t_grid		*ft_newgrid(void)
{
	t_grid	*head;
	size_t	i;

	i = 0;
	if (!(head = malloc(sizeof(t_grid))))
		return (NULL);
	head->prev = head;
	head->next = head;
	while (i < 31)
	{
		ft_gridpushback(head);
		i++;
	}
	return (head);
}
