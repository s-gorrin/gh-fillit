/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:15:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/13 05:03:32 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int                 fill_smallestsquare(int nummino)
{
    return (ft_sqrt(nummino * 4));
}

int fillit_solve(t_mino **minos, char **map, int index, int next_mino)
{
    int     next_mino;
    int     number_of_minos;

    if (!*map)
        *map = createmap(ft_sqrt(numberofminos * 4));
    if (index == ft_strlen(*map))
    {
        if (next_mino == number_of_minos)
        {
            ft_putendl(*map);
            return (1);
        }
        *map = new_map_plus_one;
        fillit_solve(minos, map, 0, 0);
    }
    if (!place_mino(minos[next_mino], map, index, next_mino))
    {
        if (index % MAP_LINE_LENGTH == 0)
        {
            if (fillit_solve(map, minos, index + 2, next_mino))
                return (1);
        }
        else
        {
            if (fillit_solve(map, minos, index + 1, next_mino))
                return (1);
        }
        return (0);
    }
    for (; next_mino < number_of_minos; next_mino++)
    {
        if (place_mino(minos[next_mino], map, index, next_mino))
        {
            if (index % MAP_LINE_LENGTH == 0)
            {
                if (fillit_solve(map, minos, index + 2, next_mino + 1))
                    return (1);
            }
            else
            {
                if (fillit_solve(map, minos, index + 1, next_mino + 1))
                    return (1);
            }
            unplace_mino(map, next_mino);
        }
    }
    return (0);
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
