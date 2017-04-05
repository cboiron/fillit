/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:53:29 by cboiron           #+#    #+#             */
/*   Updated: 2016/12/23 00:41:08 by fmiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int			ft_nb_tetri(char **argv)
{
	int		fd;
	int		len;
	char	buf[546];

	fd = open(argv[1], O_RDONLY);
	len = read(fd, buf, 546);
	if ((len + 1) % 21 != 0)
	{
		return (0);
	}
	close(fd);
	return ((len + 1) / 21);
}

void		ft_place_up_left(char *ttr, int b, int diez)
{
	int		i;

	i = 0;
	while (diez != 0)
	{
		if (ttr[i] == '#')
		{
			ttr[i - b] = '#';
			ttr[i] = '.';
			diez--;
		}
		i++;
	}
}

void		ft_check_lock(int lock, int *memo, int *left)
{
	if (lock == 0)
		*memo = *memo + 1;
	if (lock == 1 && *left > *memo)
		*left = *memo;
}

void		ft_set_up_left(char *ttr, int lock, int diez, int memo)
{
	int		i;
	int		left;
	int		up;

	i = -1;
	up = 0;
	left = 4;
	while (diez != 0)
	{
		lock = 0;
		memo = 0;
		while (ttr[++i] && ttr[i] != '\n')
		{
			if (ttr[i] == '#')
			{
				diez--;
				if (lock != 1)
					lock = 1;
			}
			ft_check_lock(lock, &memo, &left);
		}
		up += (lock == 0) ? 1 : 0;
	}
	if (up * 5 + left != 0)
		ft_place_up_left(ttr, (up * 5) + left, 4);
}

t_tetri		*ft_fill_list(t_tetri *liste, char **argv, int nb_tetri)
{
	int		fd;
	char	*buffer;
	char	c;
	int		letter;

	letter = 'A';
	liste = NULL;
	fd = open(argv[1], O_RDONLY);
	while (nb_tetri-- > 0)
	{
		if (!(buffer = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		read(fd, buffer, 20);
		read(fd, &c, 1);
		if (ft_check_tetri(buffer) == 0)
			return (NULL);
		ft_set_up_left(buffer, 0, 4, 0);
		ft_add_tetri(&liste, ft_list_tetri(buffer, letter));
		letter++;
		free(buffer);
	}
	close(fd);
	return (liste);
}
