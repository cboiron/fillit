/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:43:45 by fmiot             #+#    #+#             */
/*   Updated: 2016/12/22 19:39:32 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			ft_check_place(char **map, char **tt, int x, int y)
{
	int		i;
	int		nb_diez;
	int		ret;
	int		index[2];

	nb_diez = 0;
	i = x - 1;
	index[0] = x;
	index[1] = y;
	while (tt[++i - x] != NULL && nb_diez < 4)
	{
		if ((ret = ft_check_place_2(map, tt, i, index)) == 0)
			return (0);
		nb_diez = nb_diez + ret;
	}
	return (1);
}

void		ft_place_tetri(char **map, char **tetri, int *index, int letter)
{
	int		i;
	int		j;
	int		nb_diez;
	int		memo_y;

	nb_diez = 0;
	i = -1;
	memo_y = 0;
	while (tetri[++i] != NULL)
	{
		j = -1;
		memo_y = 0;
		while (tetri[i][++j])
		{
			if (tetri[i][j] == '.' && memo_y == 0 && i < 1)
				index[1]--;
			if (tetri[i][j] == '#')
			{
				memo_y = 1;
				map[index[0] + i][index[1] + j] = letter;
				nb_diez++;
			}
		}
	}
}

char		**ft_clean_this_tetri(char **map, int c)
{
	int		i;
	int		j;
	int		nb_char;

	nb_char = 0;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && nb_char < 4)
		{
			if (map[i][j] == c)
			{
				nb_char++;
				map[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	return (map);
}

void		ft_init(int *index)
{
	index[0] = 0;
	index[1] = 0;
}
