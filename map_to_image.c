/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:17:02 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 09:59:02 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_para_parse(t_mlx *mlx, t_map *map, int t, int j)
{
	mlx->c1->x = (j - t) * mlx->x + mlx->left_shift;
	mlx->c1->y = (t) * mlx->y + mlx->top_shift - mlx->z * map->map[t][j];
	mlx->c1->color = ft_choose_color(map->map[t][j], mlx);
	if (t < map->line - 1)
	{
		mlx->c2->x = (j - t - 1) * mlx->x + mlx->left_shift;
		mlx->c2->y = (t + 1) * mlx->y + mlx->top_shift - mlx->z * \
				map->map[t + 1][j];
		mlx->c2->color = ft_choose_color(map->map[t + 1][j], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
	if (j < map->col - 1)
	{
		mlx->c2->x = (j + 1 - t) * mlx->x + mlx->left_shift;
		mlx->c2->y = (t) * mlx->y + mlx->top_shift - mlx->z *\
				map->map[t][j + 1];
		mlx->c2->color = ft_choose_color(map->map[t][j + 1], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
}

static void	ft_para(t_mlx *mlx, t_map *map)
{
	int t;
	int j;

	if (!(mlx->c1 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	if (!(mlx->c2 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	mlx->y *= 2;
	t = 0;

	while (t < map->line)
	{
		j = 0;
		while (j < map->col)
		{
			ft_para_parse(mlx, map, t, j);
			j++;
		}
		t++;
	}
	mlx->y /= 2;
	free(mlx->c1);
	free(mlx->c2);
}

static void	ft_iso_parse(t_mlx *mlx, t_map *map, int t, int j)
{
	mlx->c1->x = (j - t) * mlx->x + mlx->left_shift;
	mlx->c1->y = (j + t) * mlx->y + mlx->top_shift - mlx->z * map->map[t][j];
	mlx->c1->color = ft_choose_color(map->map[t][j], mlx);
	if (t < map->line - 1)
	{
		mlx->c2->x = (j - t - 1) * mlx->x + mlx->left_shift;
		mlx->c2->y = (j + t + 1) * mlx->y + mlx->top_shift - mlx->z * \
				map->map[t + 1][j];
		mlx->c2->color = ft_choose_color(map->map[t + 1][j], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
	if (j < map->col - 1)
	{
		mlx->c2->x = (j + 1 - t) * mlx->x + mlx->left_shift;
		mlx->c2->y = (j + 1 + t) * mlx->y + mlx->top_shift - mlx->z *\
				map->map[t][j + 1];
		mlx->c2->color = ft_choose_color(map->map[t][j + 1], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
}

static void	ft_iso(t_mlx *mlx, t_map *map)
{
	int t;
	int j;

	if (!(mlx->c1 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	if (!(mlx->c2 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	t = 0;
	while (t < map->line)
	{
		j = 0;
		while (j < map->col)
		{
			ft_iso_parse(mlx, map, t, j);
			j++;
		}
		t++;
	}
	free(mlx->c1);
	free(mlx->c2);
}

void	ft_put_map_to_img(t_mlx *mlx, t_map *map)
{
	if (mlx->ind_choice)
		ft_iso(mlx, map);
	else
		ft_para(mlx, map);

}
