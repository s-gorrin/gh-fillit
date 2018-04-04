/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:15:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/04 08:44:28 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int                 fill_smallestsquare(int nummino)
{
    return (ft_sqrt(nummino * 4));
}

char                *fill_newsquare(int size)
{
    char    *square;
    int     i;
    int     end;

    square = ft_strnew(end);
    i = 0;
    end = size * size + size;
    while (i < end)
    {
        square[i] = '.';
        if (i % (size + 1) == 0)
            square[i] = '\n';
        i++;
    }
    return (square);
}

int                 fillit_solve(t_minos **mino, int numofminos)
{
    t_minos         **minolist;
    t_fillsquare    *square;
    int             squarenum;

    squarenum = fill_smallestsquare(numofminos)
    square = fill_newsquare(squarenum);
    while (!fill_movement(square, squarenum, 0))
    {
        squarenum++;
        square = fill_newsquare(squarenum);
    }
}

int                 fill_movement(t_fillsquare *square, int squarenum, int index)
{
    if (square[index] == "\n")

}
