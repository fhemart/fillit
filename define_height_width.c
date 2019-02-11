/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_height_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:23:15 by dhigelin          #+#    #+#             */
/*   Updated: 2017/11/27 20:39:52 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_width(char *str)
{
	int		i;
	int		highest;
	int		counter;

	highest = 0;
	i = 0;
	while (i < 19)
	{
		counter = 0;
		while (str[i] != '\n')
		{
			if (str[i] == '#')
			{
				counter++;
				if (str[i + 7] == '#' && str[i + 6] == '#' && str[i + 1] == '#')
					counter++;
				if (str[i + 5] == '#' && str[i + 4] == '#' && str[i + 1] == '#')
					counter++;
			}
			i++;
		}
		highest = (counter > highest ? counter : highest);
		i++;
	}
	return (highest);
}

void		get_height2(char *str, int *counter, int i, int j)
{
	(*counter)++;
	if (str[i + 11 + (5 * j)] == '#' &&
	str[i + 5 + (5 * j)] == '#' && str[i + 6 + (5 * j)] == '#')
		(*counter)++;
	if (str[i + 9 + (5 * j)] == '#' &&
	str[i + 4 + (5 * j)] == '#' && str[i + 5 + (5 * j)] == '#')
		(*counter)++;
}

int			get_height(char *str)
{
	int		i;
	int		j;
	int		highest;
	int		counter;

	highest = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		counter = 0;
		j = 0;
		while (j < 4)
		{
			if (str[i + (5 * j)] == '#')
				get_height2(str, &counter, i, j);
			j++;
		}
		highest = counter > highest ? counter : highest;
		i++;
	}
	return (highest);
}

void		define_height_width(t_listc *head, char *txt)
{
	int		i;
	int		j;
	char	tab[21];
	t_listc	*current;

	current = head->next;
	i = 0;
	j = 0;
	while (current != head)
	{
		while (j <= 20 && txt[j + i])
		{
			tab[j] = txt[i + j];
			j++;
		}
		tab[j] = '\0';
		current->height = get_height(tab);
		current->width = get_width(tab);
		current = current->next;
		i += 21;
		j = 0;
	}
}
