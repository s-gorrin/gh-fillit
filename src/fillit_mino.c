#include "fillit.h"

t_minos				*createminos(char **minosstr)
{
	t_minos			*minos;
	minos = (t_minos *)ft_memalloc(sizeof(t_minos));
	minos->minolist = minosstr;
	minos->num_mino = get_num_minos(minosstr);
	return (minos);
}

int					get_num_minos(char **minosstr)
{
	char **start;

	start = minosstr;
	while (*start++)
		;
	return (minosstr - start);
}