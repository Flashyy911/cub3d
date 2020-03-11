static void	swap_doubles(double *value1, double *value2)
{
	double temp;

	temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

static void	swap_ints(int *value1, int *value2)
{
	int temp;

	temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

/*
** Sort the distance of sprites from farthest to nearest
** as long as their indexes
** param 1 : number of sprites
** param 2 : distance of sprite
** param 3 : index of sprite
*/

void		sort_sprites(int n_sprites, double *d_sprite, int *i_sprite)
{
	int i;
	int j;

	i = 0;
	while (i < n_sprites - 1)
	{
		j = i + 1;
		while (j < n_sprites)
		{
			if (d_sprite[j] > d_sprite[i])
			{
				swap_doubles(&d_sprite[j], &d_sprite[i]);
				swap_ints(&i_sprite[j], &i_sprite[i]);
			}
			j++;
		}
		i++;
	}
}