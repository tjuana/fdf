/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:05:15 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 13:56:39 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



static int				ft_close(void)
{
	exit (0);
	return (0);
}


void	ft_mlx_hook(t_store *store)
{
	mlx_hook(store->mlx->win, 2, (1L << 0), &ft_button, store);
	mlx_hook(store->mlx->win, 17, (1L<<17), &ft_close, NULL);
	//mlx_hook(store->mlx->win, 4, 0, &mouse_press, store);
	//mlx_hook((store->mlx->win, 5, 0, mouse_release, store);
	//mlx_hook((store->mlx->win,, 6, 0, mouse_move, store);

}
