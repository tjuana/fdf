/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:08:34 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 14:28:58 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*ft_headline(char *headline)
{
	int	i;

	while (ft_strstr(headline, "/"))
		headline = ft_strstr(headline, "/") + 1;
	i = ft_strlen(headline);
	return (headline);
}



static int		ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	return (0);
}

int				main(int c, char **v)
{
	t_map		*map;
	t_mlx		*mlx;
	t_store		*store;


	if (c != 2)
		return (ft_usage());
	if (!(map = ft_read_map(v[1])))
		return (0);
	if (!(mlx = ft_mlx_setup(map,ft_headline(v[1]))))
		return (0);

	ft_img_setup(mlx);
	ft_color_panel(mlx);
	ft_put_map_to_img(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	if (!(store = (t_store *)malloc(sizeof(t_store))))
		return (0);
	store->map = map;
	store->mlx = mlx;
	ft_tutorial(store);
	ft_mlx_hook(store);
	mlx_loop(mlx->ptr);
	return (0);
}
