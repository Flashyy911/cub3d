
#include "../../includes/cub3d.h"

void fill_position(t_config *config)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (config->array[i])
	{
		j = 0;
		while (config->array[i][j])
		{
			if (config->array[i][j] == '2')
			{
				config->sprites[k].x = j + 0.5;
				config->sprites[k].y = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}

void ini_sprite(t_config *config)
{
	int i;
	int j;


	i = 0;
	while (config->array[i])
	{
		j = 0;
		while (config->array[i][j])
		{
			if (config->array[i][j] == '2')
				config->n_sprites++;
			j++;
		}
		i++;
	}
	config->sprites = (t_sprite*)malloc(config->n_sprites * sizeof(t_sprite));
	config->distance_sprites = malloc(config->n_sprites * sizeof(double));
	config->index_sprites = malloc(config->n_sprites * sizeof(int));
	fill_position(config);
}
