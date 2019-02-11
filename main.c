/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:49:03 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/28 12:42:28 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_block_form(char *str)
{
	int		i;
	int		touch_counter;

	touch_counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i > 3)
				(str[i - 4] == '#') ? touch_counter++ : touch_counter;
			if (i > 0)
				(str[i - 1] == '#') ? touch_counter++ : touch_counter;
			if (i < 15)
				(str[i + 1] == '#') ? touch_counter++ : touch_counter;
			if (i < 12)
				(str[i + 4] == '#') ? touch_counter++ : touch_counter;
		}
		i++;
	}
	if (touch_counter == 6 || touch_counter == 8)
		return (1);
	return (0);
}

int			check_forms(char *buff)
{
	int		i;
	int		j;
	int		counter;
	char	tab[17];

	i = 0;
	while (buff[i])
	{
		j = 0;
		counter = 0;
		while (j <= 20 && buff[j + i])
		{
			if (buff[i + j] != '\n')
			{
				tab[counter] = buff[i + j];
				counter++;
			}
			j++;
		}
		tab[counter] = '\0';
		if (!check_block_form(tab))
			return (0);
		i += 21;
	}
	return (1);
}

void		file_is_good(t_listc *head, char *buff)
{
	t_grid	*grid;
	t_listc	*current;
	size_t	bigsize;

	grid = ft_newgrid();
	ft_gridpushback(grid);
	ft_parse(buff, head);
	ft_switchbit(head);
	define_height_width(head, buff);
	current = head->next;
	bigsize = 0;
	while (current != head)
	{
		current->pos = 0;
		if (current->width > bigsize || current->height > bigsize)
			bigsize = current->height > current->width ?
			current->height : current->width;
		current = current->next;
	}
	while (rec(head, head->next, grid, bigsize) == 0)
		bigsize++;
	ft_printresult(bigsize, ft_stkresult(head, bigsize));
	ft_lstcdelhead(&head);
	ft_gridelhead(&grid);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	buff[4096];
	size_t	size;
	t_listc	*head;

	if (argc < 2 || argc > 2)
	{
		ft_putendl("usage: ./fillit [file containing up to 26 Tetriminos]");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	size = read(fd, buff, 4096);
	close(fd);
	if (!(head = ft_lstcnew()) || !check_file_length(size) ||
	!ft_filecheck(buff, (size / 20) - ((size / 20) / 20)) || !check_forms(buff))
	{
		ft_putendl("error");
		return (0);
	}
	file_is_good(head, buff);
	return (1);
}
