/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:22:34 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/04 14:29:38 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_THIRD_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7
# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250

# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "math.h"

typedef enum
{
	false,
	true
}	t_bool;

typedef struct		s_coord
{
	double				x;
	double				y;
	double				z;
	int				color;
}					t_coord;

typedef struct 		s_line
{
		int			len;
		double		dx;
		double		dy;
		double		x;
		double		y;
		int			i;
		double		mix;
}					t_line;


typedef struct		s_map
{
	int				**map;
	int				line;
	int				col;
}					t_map;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	int				*str;
	int				width;
	int				height;
	int				x;
	int				y;
	double			z;
	int				top_shift;
	int				left_shift;
	int				ind_choice;
	int				pan_choice;
	int				panel[5][5];
	t_coord			*c1;
	t_coord			*c2;
}					t_mlx;

typedef struct		s_store
{
	t_map			*map;
	t_mlx			*mlx;
}					t_store;

t_map				*ft_read_map(char *file);
void				ft_count_line_and_column(t_map *map, char *line);
int					ft_count_values(char *str);
void				ft_display_map(t_map *map);
t_mlx				*ft_mlx_setup(t_map *map, char *title);
void				ft_img_setup(t_mlx *mlx);
int					ft_button(int key, t_store *store);
void				ft_color_panel(t_mlx *mlx);
void				ft_line(t_mlx *mlx, t_coord *c1, t_coord *c2);
int					ft_choose_color(int alt, t_mlx *mlx);
void				ft_put_map_to_img(t_mlx *mlx, t_map *map);
void				ft_mlx_hook(t_store *store);
void				ft_move(int key, t_store *store);
void				ft_zoom(int key, t_store *store);
int					ft_z_max(t_map *map);
int					ft_small_coord(t_map *map);
void				ft_tutorial(t_store *stock);

#endif
