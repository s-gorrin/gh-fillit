/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:12:07 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/13 05:04:29 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>

# define BUF_SIZE 600
# define MINO_STR_LEN 21
# define MINO_STR_LINELEN 4
# define MINO_STR_MAXNL 5

typedef char*       t_mino;

typedef char*       t_fillsq;
/*
** File Functions
*/
t_mino              **fill_getminofromfile(char *minostr);
int                 isvalidminostr(char *minostr, int minoindex);
t_mino              strtomino(char *minostr);
int                 isvalidmino(t_mino *mino);

/*
** Fillit Solving Algo
*/
int                 fill_smallestsquare(int nummino);
int                 fill_movement();
int                 fill_isvalidplacemino();
int                 fillit_solve(t_mino **minos, char **map, int index, int next_mino)

#endif
