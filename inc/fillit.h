/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:12:07 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/12 22:22:49 by sgorrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>

# define BUFF_SIZE 600
# define MINO_STR_LEN 21
# define MINO_STR_LINELEN 4
# define MINO_STR_MAXNL 5

typedef char*	t_mino;

/*
** Reading in
*/
t_mino			**file_to_mino_list(char *file);
int				is_valid_mino_str(char const *minostr, int mindex);
t_mino			*mino_id(char *minostr);

/*
** Solving
*/
int				map_line_len(char const *map);
int				place_mino(t_mino *mino, char **map, int i, int letter);
int				unplace_mino(char **map, int letter);
int				fillit_solver(t_minos **mino, int numofminos);

#endif
