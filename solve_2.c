/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:42:00 by fmiot             #+#    #+#             */
/*   Updated: 2016/12/22 19:40:29 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char		**ft_create_square(int size)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(map) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(map[i]) * size + 1)))
			return (NULL);
		ft_memset(map[i], '.', size);
		map[i][size] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int			ft_sqrt(int nb_tetri)
{
	int		tmp;

	nb_tetri = nb_tetri * 4;
	tmp = 0;
	while (tmp < nb_tetri)
	{
		if (tmp * tmp >= nb_tetri)
			return (tmp);
		else
			tmp++;
	}
	return (0);
}

int			ft_check_place_2(char **map, char **tt, int i, int *k)
{
	int		j;
	int		nb_diez;
	int		memo_y;

	nb_diez = 0;
	j = -1;
	memo_y = 0;
	while (tt[i - k[0]][++j] && nb_diez < 4)
	{
		if ((map[i] == NULL || map[i][k[1] + j] == 0) && tt[i - k[0]][j] == '#')
			return (0);
		if (tt[i - k[0]][j] == '.' && memo_y == 0 && i - k[0] < 1)
			k[1]--;
		if (tt[i - k[0]][j] == '#')
		{
			if (!(map[i][k[1] + j] == '.'))
				return (0);
			memo_y = 1;
			nb_diez++;
		}
	}
	return (nb_diez);
}

void		ft_del_list(t_tetri **list)
{
	void	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	list = NULL;
}
