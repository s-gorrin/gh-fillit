/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_getminofromfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <ssnelgro@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:30:56 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/04/04 05:01:22 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int                 isvalidchar(char c)
{
    char    *valid;

    valid = "\n.#";
    while(*valid++)
        if (*valid == c)
            return (1);
    return (0);
}

int                 isvalidminostr(char *minostr, int minoix)
{
    char    *mino;
    int     hashcount;
    int     nllinecount;
    int     charcount;
    int     index;

    mino = &minostr[minoix];
    hashcount = 0;
    nllinecount = 0;
    charcount = 0;
    index = 0;
    while (mino[index] != '\0')
    {
        if (mino[index] == '.')
            charcount++;
        else if (mino[index] == '#')
        {
            hashcount++;
            if (hashcount > 4)
                return (0);
            charcount++;
        }
        else if (mino[index] == '\n')
        {
            nllinecount++;
            if (nllinecount == MINO_STR_MAXNL - 1 &&
                    mino[index + 1] == '\n' &&
                    index == MINO_STR_LEN)
                return (1); //end condition
            if (charcount > MINO_STR_LINELEN)
                return (0);
            charcount = 0;
        }
        else
            return (0);
        index++;
    }
    return (0);
}

char                *getminofilechar(char *filepath)
{
    char        *minofile;
    char        buf[BUF_SIZE + 1];
    int         bytesread;
    int         fd;

    fd = open(filepath, O_RDONLY);
    bytesread = read(fd, &buf, BUF_SIZE);
    buf[bytesread] = '\0';
    minofile = ft_strnew(bytesread + 1);
    ft_memcpy(minofile, buf, bytesread);
    close(fd);
    return(minofile);
}

t_mino              *minostrtomino(char *minofile,int index)
{
    t_mino  *finalmino;
    char    *mino;
    int     hashes;
    int     i;

    mino = &minofile[index];
    hashes = 1;
    finalmino = (t_mino *)ft_strnew(4);
    i = 0;
    while (*mino != '#')
        mino++;
    while (mino[hashes])
    {
        if (mino[hashes] == '#')
        {
            finalmino[i] = ft_itoa(hashes);
            i++;
        }
        hashes++;
    }
    return (finalmino);
}

t_mino              **fill_getminofromfile(char *filepath)
{
    t_mino  **minosfromfile;
    char    *minofile;
    t_mino  *tmpminostr;
    int     index;

    minofile = getminofilechar(filepath);
    index = 0;
    minosfromfile = (t_mino **)ft_memalloc(sizeof(t_mino *) * 27);
    while (minofile[index])
    {
        if (isvalidminostr(minofile, index))
        {
            tmpminostr = minostrtomino(minofile, index);
            minosfromfile[index / MINO_STR_LEN] = tmpminostr;
            index += MINO_STR_LEN;
        }
        else
            return (NULL);
    }
    minosfromfile[index / MINO_STR_LEN] = '\0';
    return (minosfromfile);
}
