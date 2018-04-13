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
# define MINO_STR_MAXNL 5

/*
** Reading in
*/
char			**file_to_mino_list(char *file);
int				is_valid_mino_str(char const *minostr, int mindex);
char			*mino_id(char *minostr);

/*
** Solving
*/
int				map_line_len(char const *map);
int				place_mino(char *mino, char **map, int i, int letter);
int				unplace_mino(char **map, int letter);
int				fillit_solver(char **mino, int numofminos);

#endif
