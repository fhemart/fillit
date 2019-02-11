/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 01:48:30 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/28 12:21:24 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

typedef	struct		s_listc
{
	unsigned short	val;
	size_t			pos;
	size_t			width;
	size_t			height;
	struct s_listc	*next;
	struct s_listc	*prev;
}					t_listc;

typedef struct		s_grid
{
	unsigned int	val;
	struct s_grid	*next;
	struct s_grid	*prev;
}					t_grid;

int					rec(t_listc *blockhead, t_listc *block,
	t_grid *head, size_t size);
int					isempty(t_grid *head, size_t pos);
int					isok(t_listc *block, t_grid *head, size_t pos, size_t size);
int					movepos(size_t *current_pos, size_t size);
void				ft_stockdata(char *str, t_listc *head);
void				ft_parse(char *buff, t_listc *head);
int					ft_block_check(char *block, size_t i);
int					ft_filecheck(char *buff, size_t nblock);
t_listc				*ft_lstcnew(void);
void				ft_lstcpushback(t_listc *head, unsigned short val);
void				ft_lstcshow(t_listc *head);
void				ft_lstcdel(t_listc *head);
void				ft_lstcdelhead(t_listc **head);
void				ft_switchbit(t_listc *head);
void				ft_gridpushback(t_grid *head);
t_grid				*ft_newgrid(void);
void				ft_gridel(t_grid *head);
void				ft_gridelhead(t_grid **head);
void				ft_gridshow(t_grid *head);
void				ft_putlnbr(unsigned long n);
size_t				ft_getindex(unsigned short pos, size_t i);
t_grid				*ft_getline(unsigned short pos, t_grid *gridline);
size_t				ft_foreachbit(t_grid *head, t_listc *block, unsigned
	short pos, size_t (*f)(t_listc *, t_grid *, unsigned short, size_t));
size_t				ft_setbit(t_listc *block, t_grid *line,
	unsigned short pos, size_t bit);
size_t				ft_cmpbit(t_listc *block, t_grid *line,
	unsigned short pos, size_t bit);
size_t				ft_unsetbit(t_listc *block, t_grid *line,
	unsigned short pos, size_t bit);
char				*ft_stkresult(t_listc *blockhead, size_t len);
void				ft_printresult(size_t len, const char *s);
void				ft_resetgrid(t_grid *head);
unsigned long		ft_pow(unsigned long nb, unsigned long pow);
int					convert_bit_to_pos(size_t size, size_t block_pos,
	int bit_pos);
int					checkempty(size_t size, t_grid *head);
int					leftblock(t_listc *current, t_listc *head);
int					check_file_length(int size);
void				define_height_width(t_listc *head, char *txt);

#endif
