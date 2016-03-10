/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:50:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/10 15:23:04 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		usage(char *exe)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(exe, 2);
	ft_putstr_fd(" <File>\n", 2);
}

int				main(int ac, char **av)
{
	if (ac != 2)
		usage(av[0]);
	else
		fillit(ac, av);
	return (0);
}
