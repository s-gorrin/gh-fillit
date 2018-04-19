
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
