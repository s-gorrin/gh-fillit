/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:12:07 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/12 23:12:47 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>

# define BUFF_SIZE 600
# define MINO_STR_LEN 21
# define MINO_STR_LINELEN 4
# define MINO_STR_NL 5
# define MINO_STR_HASH 4
# define MINO_STR_DOTS 12
# define MAX_MINOS 26

typedef struct	s_minos
{
	char		**minolist;
	int			num_mino;
}				t_minos;

typedef struct	s_map
{
	char		*mapstr;
	int			mapsize;
}				t_map;
/*
** Reading in
*/
char			**file_to_mino_list(char *file);
char			*file_to_str(char *filepath);
int				mino_file_str_verif(char *mino_file_str);
int				verify_char_counts(int dots, int hases, int nls, int num_minos);
char 			**minofile_minostr_check(char *mino_file_str, int num_minos);
char 			*minostr_check(char *mino_file_str, int index);
char			*mino_id(char *minostr);

/*
** Solving
*/
int				place_mino(char *mino, char **map, int i, int letter);
int				unplace_mino(char **map, int letter);
int				fillit_solve(t_minos *minos, t_map *map, int index, int next_mino);
void			fillit_cleanup(t_minos *minos, t_map *map);

/*
** Map
*/
t_map			*createmap(int size);
char			*fill_newsquare(int size);
int				map_line_len(char *map);
t_map			*new_map_plus_one(t_map	*current_map);

/*
** Mino
*/
t_minos			*createminos(char **minosstr);
int				get_num_minos(char **minosstr);

/*
** Mino placement
*/
int				mod_num(char *map, int num);
int				to_int(char hex);
#endif
