/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:59:21 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 14:29:23 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_zoom(int key, t_store *store)
{
	if (key == 115  && store->mlx->x < 10000 && store->mlx->y < 5000 && \
			store->mlx->z < 2500)
	{
		store->mlx->x += 5;
		store->mlx->y += 3;
		store->mlx->z += 1;
	}
	else if (key == 119 && store->mlx->x > 1 && store->mlx->y > 1 && \
			store->mlx->z > -100)
	{
		store->mlx->x -= 5;
		store->mlx->y -= 3;
		store->mlx->z -= 1;
	}
	else if (key == 116 && store->mlx->z < 2500)
		store->mlx->z += 0.7;
	else if (key == 121 && store->mlx->z > -100)
		store->mlx->z -= 0.7;
}

void		ft_move(int key, t_store *store)
{
	if (key == 126 && store->mlx->top_shift > -10000)
		store->mlx->top_shift -= 17;
	else if (key == 125 && store->mlx->top_shift < 10000)
		store->mlx->top_shift += 17;
	else if (key == 123 && store->mlx->left_shift > -10000)
		store->mlx->left_shift -= 17;
	else if (key == 124 && store->mlx->left_shift < 10000)
		store->mlx->left_shift += 17;
}

void	ft_tutorial(t_store *stock)
{
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 25, 0xf0e68c, "   You know what???");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 50, 0xf0e68c, "ESC               exit");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 75, 0xff00, "R                reset");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 100, 0xff3030, "TAB              perspective");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 125, 0xfffff0, "PAGE UP / DOWN   height");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 150, 0xff3030, "ARROWS           move");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 175, 0xfffff0, "HOME / END       zoom");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 200, 0xff3030, "NUMBERS          colors");
}

static void	ft_reset(t_store *stock)
{
	stock->mlx->x = 32 - 4 * ft_small_coord(stock->map);
	stock->mlx->y = 16 - 2 * ft_small_coord(stock->map);
	stock->mlx->z = 8 - 1 * ft_small_coord(stock->map);
	stock->mlx->top_shift = stock->mlx->y
		+ stock->mlx->z * ft_z_max(stock->map);
	stock->mlx->left_shift = stock->mlx->x * stock->map->line;
	stock->mlx->ind_choice = 1;
	stock->mlx->pan_choice = 0;
}

int				ft_button(int key, t_store *store)
{
	if (key == 53)
		exit (0);
	else if ((key >= 18 && key <= 21) || key == 23)
		store->mlx->pan_choice = key == 23 ? 4 : key - 18;
	else if (key == 115 || key == 116 || key == 119 || key == 121)
		ft_zoom(key, store);
	else if (key >= 123 && key <= 126)
		ft_move(key, store);
	else if (key == 15)
		ft_reset(store);
	else if (key == 48)
		store->mlx->ind_choice = 0;
	ft_bzero(store->mlx->str, store->mlx->width * store->mlx->height *\
			sizeof(int));
	ft_put_map_to_img(store->mlx, store->map);
	mlx_put_image_to_window(store->mlx->ptr, store->mlx->win, store->mlx->img,\
				 0, 0);
	ft_tutorial(store);
	return (0);
}
