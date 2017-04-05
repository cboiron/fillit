/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 02:40:04 by cboiron           #+#    #+#             */
/*   Updated: 2016/12/22 19:43:05 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**ft_check_bound(char **map, t_tetri **tmp, int *index, int *size_map)
{
	if (map[index[0]] == NULL && (*tmp)->letter == 'A')
	{
		ft_free_map(map);
		map = ft_create_square(++(*size_map));
		if (!map)
			return (NULL);
		ft_init(index);
	}
	else if (map[index[0]] == NULL)
	{
		*tmp = (*tmp)->prev;
		ft_init(index);
		map = ft_clean_this_tetri(map, (*tmp)->letter);
		index[0] = (*tmp)->pos[0];
		index[1] = (*tmp)->pos[1] + 1;
	}
	return (map);
}

void	ft_place_on_map(char **map, t_tetri **tmp, int *index)
{
	(*tmp)->pos[0] = index[0];
	(*tmp)->pos[1] = index[1];
	ft_place_tetri(map, (*tmp)->tetri, index, (*tmp)->letter);
	*tmp = (*tmp)->next;
	ft_init(index);
}

char	**ft_solve(t_tetri *liste, int size_map, char **map)
{
	int		index[2];
	t_tetri *tmp;

	tmp = liste;
	index[0] = 0;
	index[1] = 0;
	while (tmp)
	{
		if (!map)
			return (NULL);
		if (map[index[0]] == NULL)
			map = ft_check_bound(map, &tmp, index, &size_map);
		else if (map[index[0]][index[1]] == '\0')
		{
			index[0]++;
			index[1] = 0;
		}
		else if (map[index[0]][index[1]] != '.')
			index[1]++;
		else if (ft_check_place(map, tmp->tetri, index[0], index[1]))
			ft_place_on_map(map, &tmp, index);
		else
			index[1]++;
	}
	return (map);
}
