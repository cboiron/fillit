/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 02:07:46 by cboiron           #+#    #+#             */
/*   Updated: 2016/12/23 00:27:15 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int			main(int argc, char *argv[])
{
	t_tetri	*list;
	char	**map;
	int		size_map;

	map = NULL;
	list = NULL;
	if (argc != 2)
	{
		ft_putstr("usage : fillit source_file");
		return (0);
	}
	list = ft_fill_list(list, argv, ft_nb_tetri(argv));
	if (list == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	size_map = ft_sqrt(ft_nb_tetri(argv));
	map = ft_solve(list, size_map, ft_create_square(size_map));
	if (!map)
		return (0);
	ft_print_map(map);
	ft_free_map(map);
	ft_del_list(&list);
	return (0);
}
