/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:05:20 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 13:15:48 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void rotate_x(int *y, int *z, double alpha)
{
	int py;

	py = *y;
	*y = py * cos(alpha) + *z * sin(alpha);
	*z = -py * sin(alpha) + *z * cos(alpha);
}

static void rotate_y(int *x, int *z, double beta)
{
	int px;

	px = *x;
	*x = px * cos(beta) + *z * sin(beta);
	*z = -px * sin(beta) + *z * cos(beta);
}

static void rotate_z(int *y, int *x, double gamma)
{
	int py;
	int px;

	px = *x;
	py = *y;
	*x = px * cos(gamma) - *y * sin(gamma);
	*y = -px * sin(gamma) + *y * cos(gamma);
}

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

/*
** Project coordinate to 2D plane
*/

t_coord		project(t_coord p, t_store *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->mlx->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->mlx->height * fdf->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, fdf->camera->alpha);
	rotate_y(&p.x, &p.z, fdf->camera->beta);
	rotate_z(&p.x, &p.y, fdf->camera->gamma);
	//if (fdf->camera->projection == ISO)
		//iso(&p.x, &p.y, p.z);
	p.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_offset + MENU_WIDTH;
	p.y += (HEIGHT + fdf->mlx->height * fdf->camera->zoom) / 2
												+ fdf->camera->y_offset;
	return (p);
}
