/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:36:43 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 14:20:51 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_color_panel(t_mlx *mlx)
{
	mlx->panel[0][0] = 0xfffafa;
	mlx->panel[0][1] = 0xfffafa;
	mlx->panel[0][2] = 0xfffafa;
	mlx->panel[0][3] = 0xfffafa;
	mlx->panel[0][4] = 0xfffafa;
	mlx->panel[1][0] = 0xff00;
	mlx->panel[1][1] = 0xf0e68c;
	mlx->panel[1][2] = 0xf0e68c;
	mlx->panel[1][3] = 0xffd700;
	mlx->panel[1][4] = 0xffff00;
	mlx->panel[2][0] = 0xff3030;
	mlx->panel[2][1] = 0xee2c2c;
	mlx->panel[2][2] = 0xcd2626;
	mlx->panel[2][3] = 0x8b1a1a;
	mlx->panel[2][4] = 0xff4040;
	mlx->panel[3][0] = 0xa9a9a9;
	mlx->panel[3][1] = 0xcdba96;
	mlx->panel[3][2] = 0xc0ff3e;
	mlx->panel[3][3] = 0xeeee;
	mlx->panel[3][4] = 0xfffff0;
	mlx->panel[4][0] = 0xff3030;
	mlx->panel[4][1] = 0xe9967a;
	mlx->panel[4][2] = 0xdaa520;
	mlx->panel[4][3] = 0x708090;
	mlx->panel[4][4] = 0xff3030;
}

int			ft_choose_color(int alt, t_mlx *mlx)
{
	if (alt <= 0)
		return (mlx->panel[mlx->pan_choice][0]);
	else if (alt <= 10)
		return (mlx->panel[mlx->pan_choice][1]);
	else if (alt <= 20)
		return (mlx->panel[mlx->pan_choice][2]);
	else if (alt <= 30)
		return (mlx->panel[mlx->pan_choice][3]);
	else
		return (mlx->panel[mlx->pan_choice][4]);
}

static void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = color;
}


void		ft_line(t_mlx *mlx, t_coord *c1, t_coord *c2)
{
	t_line *line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ABS(c2->x - c1->x) >= ABS(c2->y - c1->y))
		line->len = ABS(c2->x - c1->x);
	else
		line->len = ABS(c2->y - c1->y);
	line->dx = (c2->x - c1->x) / line->len;
	line->dy = (c2->y - c1->y) / line->len;
	line->x = c1->x + 0.5;
	line->y = c1->y + 0.5;
	line->i = 1;
	while (line->i <= line->len && line->x < mlx->width
			&& line->y < mlx->height)
	{
		line->mix = line->i / (double)line->len;
		ft_fill_pixel(mlx, (int)line->x, (int)line->y,
				c1->color * (1 - line->mix) + c2->color * line->mix);
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(line);
}
