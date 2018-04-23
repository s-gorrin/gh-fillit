
//From file_to_mino_list
/*
int			mino_file_str_verif(char *mino_file_str)
{
	int hashes;
	int nls;
	int num_minos;
	int dots;

	hashes = 0;
	nls = 0;
	num_minos = 0;
	dots = 0;
	while (*mino_file_str)
	{
		if (*mino_file_str == '#')
			hashes++;
		else if (*mino_file_str == '\n')
		{
			if (*(mino_file_str + 1) == '\n')
				num_minos++;
			nls++;
		}
		else if (*mino_file_str == '.')
			dots++;
		else
			return (0);
		mino_file_str++;
	}
	if (!(verify_char_counts(dots, hashes, nls, num_minos)))
		return (0);
	return (num_minos);
}

int			verify_char_counts(int dots, int hashes, int nls, int num_minos)
{
	if (nls % MINO_STR_NL != 0)
		return (0);
	if (dots % MINO_STR_DOTS != 0)
		return (0);
	if (hashes % MINO_STR_HASH != 0)
		return (0);
	if (num_minos > MAX_MINOS || num_minos < 1)
		return (0);
	// if ((nls + dots + hashes) % MINO_STR_LEN)
	// 	return (0);
	return (1);
}
*/


//From unplace_mino:
/*
** @Function: unplaces a mino by changing its letter to a '.'
** @Param1: map that might contain the mino to be unplaced
** @Param2: letter of the mino being looked for
** @Return: 1 if the letter was unplaced, 0 if it was not found
*/
/*
int	unplace_mino(t_map *map, t_minos *mino, int letter)
{
	int	i;
	int	flag;
	int	loc;

	loc = t_mino->location[letter];
	i = 0;
	flag = 0;
	while (map->mapstr[i] != '\0')
	{
		if (map->mapstr[i] == letter + 'A')
		{
			map->mapstr[i] = '.';
			flag++;
		}
		i++;
	}
	t_mino->location[letter] = 0;
	return (loc)
}


int	unplace_mino(t_mino *mino, t_map *map, int i)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;
	int		loc;
	char	let;

	let = mino->letter;
	loc = mino->location;
	n1 = mod_num(map->mapsize, to_int(mino->minostr[0]));
	n2 = mod_num(map->mapsize, to_int(mino->minostr[1]));
	n3 = mod_num(map->mapsize, to_int(mino->minostr[2]));
	n4 = mod_num(map->mapsize, to_int(mino->minostr[3]));
	if ((map->mapstr)[i + n1] == let && (map->mapstr)[i + n2] == let &&
			(map->mapstr)[i + n3] == let && (map->mapstr)[i + n4] == let);
	{
		(map->mapstr)[i + n1] = '.';
		(map->mapstr)[i + n2] = '.';
		(map->mapstr)[i + n3] = '.';
		(map->mapstr)[i + n4] = '.';
		mino->location = -1;
		return (loc);
	}
	else
		return (0);
}
*/


//From place_mino
/*
int	place_mino(t_mino *mino, t_map *map, int i)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;

	if (ft_strchr(map->mapstr, mino->letter))
		return (0);
	n1 = mod_num(map->mapsize, to_int(mino->minostr[0]));
	n2 = mod_num(map->mapsize, to_int(mino->minostr[1]));
	n3 = mod_num(map->mapsize, to_int(mino->minostr[2]));
	n4 = mod_num(map->mapsize, to_int(mino->minostr[3]));
	if ((map->mapstr)[i + n1] == '.' && (map->mapstr)[i + n2] == '.' &&
			(map->mapstr)[i + n3] == '.' && (map->mapstr)[i + n4] == '.')
	{
		(map->mapstr)[i + n1] = mino->letter;
		(map->mapstr)[i + n2] = mino->letter;
		(map->mapstr)[i + n3] = mino->letter;
		(map->mapstr)[i + n4] = mino->letter;
		mino->location = i;
		return (1);
	}
	else
		return (0);
}
*/


//From check_tools
//
/*
int	mod_num(int line_len, int num)
{
	if (line_len == 3)
	{
		if (num >= 5 && num <= 7)
			return (num - 1);
		if (num == 10 || num == 11)
			return (num - 2);
	}
	if (line_len > 4)
	{
		if (num >= 5 && num <= 7)
			return (num + (line_len - 4));
		if (num == 10 || num == 11)
			return (num + (line_len - 2));
		if (num == 15)
			return (num + (line_len - 0));
	}
	else
		return (num);
	return (num);
}
*/
