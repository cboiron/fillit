/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:39:54 by cboiron           #+#    #+#             */
/*   Updated: 2016/12/22 15:40:08 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int		ft_check_format(char *str)
{
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
	{
		return (0);
	}
	return (1);
}

int		ft_check_nbd(char *str)
{
	int	i;
	int	nb_diez;
	int	nb_point;

	i = 0;
	nb_diez = 0;
	nb_point = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			nb_diez++;
		if (str[i] == '.')
			nb_point++;
		i++;
	}
	if (nb_diez != 4 || nb_point != 12)
	{
		return (0);
	}
	return (1);
}

int		ft_check_contacts(char *str, int i)
{
	int	contacts;

	contacts = 0;
	if (str[i - 1] == '#')
		contacts++;
	if (str[i + 1] == '#')
		contacts++;
	if (str[i + 5] == '#')
		contacts++;
	if (str[i - 5] == '#')
		contacts++;
	return (contacts);
}

int		ft_check_valid(char *str)
{
	int	i;
	int	contacts;
	int	contacts_max;

	contacts_max = 0;
	contacts = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			contacts = ft_check_contacts(str, i);
			if (contacts == 0)
				return (0);
			if (contacts > contacts_max)
				contacts_max = contacts;
		}
		i++;
	}
	if (contacts_max < 2)
	{
		return (0);
	}
	return (1);
}

int		ft_check_tetri(char *str)
{
	if (ft_check_format(str))
		if (ft_check_nbd(str))
			if (ft_check_valid(str))
				return (1);
	return (0);
}
