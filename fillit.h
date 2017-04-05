/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:54:23 by cboiron           #+#    #+#             */
/*   Updated: 2016/12/23 00:40:55 by fmiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_tetri
{
	char			**tetri;

	int				pos[2];
	int				letter;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

int					ft_check_place(char **map, char **tetri, int x, int y);
char				**ft_check_bound(char **map, t_tetri **tmp, \
					int *index, int *size_map);
void				ft_place_tetri(char **map, char **tetri, \
					int *i, int letter);
char				**ft_clean_this_tetri(char **map, int c);
void				ft_init(int *index);
int					ft_check_place_2(char **map, char **tt, int i, int *k);
int					ft_sqrt(int nb_tetri);
char				**ft_create_square(int size);
void				ft_free_map(char **map);
char				**ft_solve(t_tetri *liste, int nb_tetri, char **map);
int					ft_check_tetri(char *buffer);
void				ft_del_list(t_tetri **list);
int					ft_nb_tetri(char **argv);
t_tetri				*ft_fill_list(t_tetri *list, char **argv, int nb_tetri);
void				ft_add_tetri(t_tetri **list, t_tetri *elem);
t_tetri				*ft_list_tetri(char *buf, int letter);

#endif
