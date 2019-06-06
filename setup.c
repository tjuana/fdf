/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:03:41 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 14:15:47 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_z_max(t_map *map)
{
	int	max;
	int	t;
	int	j;

	max = -2147483648;
	t = 0;
	while (t < map->line)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->map[t][j] > max)
				max = map->map[t][j];
			j++;
		}
		t++;
	}
	return (max);
}

int		ft_small_coord(t_map *map)
{
	if (map->line >= 150 || map->col >= 150)
		return (7);
	if (map->line >= 100 || map->col >= 100)
		return (6);
	if (map->line >= 50 || map->col >= 50)
		return (5);
	if (map->line >= 25 || map->col >= 25)
		return (2);
	return (0);
}

static int		ft_small_win(t_map *map)
{
	if (map->line <= 10 && map->col <= 10)
		return (2);
	if (map->line <= 24 && map->col <= 24)
		return (1);
	return (0);
}

void	ft_img_setup(t_mlx *mlx)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
}

t_mlx	*ft_mlx_setup(t_map *map, char *headline)
{
	t_mlx	*mlx;
	int		tony_size;
	int		jhony_coord;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->ptr = mlx_init();
	tony_size = ft_small_win(map);
	mlx->width = 1920 - 600 * tony_size;
	mlx->height = 1080 - 300 * tony_size;
	jhony_coord = ft_small_coord(map);
	mlx->x = 32 - 4 * jhony_coord;
	mlx->y = 16 - 2 * jhony_coord;
	mlx->z = 8 - 1 * jhony_coord;
	mlx->top_shift = mlx->y + mlx->z * ft_z_max(map);
	mlx->left_shift = mlx->x * map->line;
	mlx->ind_choice = 1;
	mlx->pan_choice = 0;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, headline);
	return (mlx);
}
