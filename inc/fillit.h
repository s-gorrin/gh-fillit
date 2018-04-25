/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:12:07 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/24 14:18:25 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>

# define MAP_AREA (map->mapsize * (map->mapsize + 1))
# define BUFF_SIZE 600
# define MINO_STR_LEN 21
# define MINO_STR_LINELEN 4
# define MINO_STR_NL 5
# define MINO_STR_HASH 4
# define MINO_STR_DOTS 12
# define MAX_MINOS 26

typedef struct	s_count
{
	int			hashes;
	int			dots;
	int			nls;
	int			num_minos;
}				t_count;

typedef struct	s_mino
{
	char		*minostr;
	int			location;
	char		letter;
}				t_mino;

typedef struct	s_map
{
	char		*mapstr;
	int			mapsize;
	int			num_mino;
    int			placed_minos;
}				t_map;
/*
** Reading in
*/
t_mino			**file_to_mino_list(char *file, t_map *map);
char			*file_to_str(char *filepath);
//int				mino_file_str_verif(char *mino_file_str);
//int				verify_char_counts(int dots, int hases, int nls, int num_minos);
int				verify_input(char const *minostr);
t_mino 			**minofile_minostr_check(char *mino_file_str, int num_minos);
char			*mino_id(char *minostr);

/*
** Solving
*/
int				place_mino(t_mino *mino, t_map *map, int i);
int				unplace_mino(t_mino *mino, t_map *map);
void			fillit_solver(t_mino **mino_list, t_map *map);

/*
** Map
*/
t_map			*createmap(void);
char			*fill_newsquare(int size);
int				map_line_len(char *map);
t_map			*new_map_plus_one(t_map *current_map);
void			update_mapstr(int size, t_map *map);

/*
** Mino
*/
t_mino			*createmino(char *minosstr, int index);
int				get_num_minos(char **minosstr);

/*
** Mino placement
*/
int				mod_num(int line_len, int num);
int				to_int(char hex);

void			fillit_cleanup(t_map *map, t_mino **mino);

#endif
