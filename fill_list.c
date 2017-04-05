/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 23:04:42 by cboiron           #+#    #+#             */
/*   Updated: 2016/12/23 00:41:42 by fmiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

char		**ft_split_tetri(char *buf)
{
	int		i;
	int		k;
	int		j;
	char	**tetri;

	i = 0;
	if (!(tetri = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	k = 0;
	while (k < 4)
	{
		if (!(tetri[k] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		j = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			tetri[k][j++] = buf[i++];
		tetri[k++][4] = '\0';
		if (buf[i] == '\n')
			i++;
	}
	tetri[4] = NULL;
	return (tetri);
}

t_tetri		*ft_list_tetri(char *buf, int letter)
{
	t_tetri	*elem;

	if (!(elem = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	elem->tetri = ft_split_tetri(buf);
	if (!elem->tetri)
		return (NULL);
	elem->pos[0] = 0;
	elem->pos[1] = 0;
	elem->next = NULL;
	elem->prev = NULL;
	elem->letter = letter;
	return (elem);
}

void		ft_add_tetri(t_tetri **liste, t_tetri *elem)
{
	t_tetri	*tmp;

	tmp = *liste;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		elem->prev = tmp;
		tmp->next = elem;
	}
	else
	{
		*liste = elem;
	}
}
