/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:17:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/23 17:11:08 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		replace_char(char **tab_piece)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = 'A';
	while (tab_piece[i])
	{
		j = 0;
		while (tab_piece[i][j])
		{
			if (tab_piece[i][j] == '#')
				tab_piece[i][j] = c;
			++j;
		}
		++c;
		++i;
	}
}

char		**split_pieces(char *pieces)
{
	char	**tab_piece;
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 0;
	j = 0;
	tab_piece = (char**)ft_memalloc(sizeof(char*) * (count_piece(pieces) + 1));
	if (tab_piece)
	{
		while (pieces[i])
		{
			if (pieces[i] == '\n' && pieces[i + 1] == '\n')
			{
				tab_piece[a] = ft_strsub(pieces, j, i - j + 1);
				j = i + 2;
				++a;
			}
			++i;
		}
		tab_piece[a] = ft_strsub(pieces, j, i - j);
	}
	return (tab_piece);
}

int		count_piece(char *pieces)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (pieces[i])
	{
		if (pieces[i] == '\n' && pieces[i + 1] == '\n')
			++j;
		i++;
	}
	return (j + 1);
}

int		get_pieces(char *pieces, t_piece **piece)
{
	char	**tab_piece;
	int		nb_piece;

	nb_piece = 0;
	tab_piece = split_pieces(pieces);
	if (!tab_piece)
		return (0);
	if (check_pieces(tab_piece))
	{
		*piece = format_pieces_from_char(tab_piece, count_piece(pieces));
		ft_free_tab(tab_piece);
		return (1);
	}
	else
	{
		ft_free_tab(tab_piece);
		ft_putendl_fd("error", 2);
		return (0);
	}
}

t_piece	*format_pieces_from_char(char **tab, int nb)
{
	int	i;
	t_piece		*piece;

	i = 0;
	piece = NULL;
	while (i < nb)
	{
		add_piece_end(&piece, create_piece(tab[i], i));
		i++;
	}
	return (piece);
}



void	add_piece_end(t_piece **first, t_piece *piece)
{
	t_piece	*tmp;

	tmp = *first;
	if (!tmp)
		*first = piece;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = piece;
	}
}

int	get_file(int fd, char **pieces)
{
	char		buf[BUFF_SIZE + 1];
	ssize_t		ret;
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*pieces)
			*pieces = ft_strdup(buf);
		else
		{
			tmp = *pieces;
			*pieces = ft_strjoin(*pieces, buf);
		}
		free(tmp);
	}
	if (ret == -1)
		return (0);
	return (1);
}
