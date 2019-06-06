/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:37:17 by tjuana            #+#    #+#             */
/*   Updated: 2019/06/02 18:55:42 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_map(t_map *map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->col)
		{
			ft_putnbr(map->map[i][j++]);
			(j < map->col) ? ft_putchar('\t') : 0;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_count_values(char *str)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str)
			nb++;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
			str++;
	}
	return (nb);
}

void	ft_count_line_and_column(t_map *map, char *line)
{
	map->line++;
	map->col = ft_count_values(line);
	free(line);
}

t_map	*ft_read_map(char *file)
{
	t_map	*map;
	int		fd;
	char 	*line;
	int		fd2;
	int		i;
	int		j = 0;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
		ft_count_line_and_column(map, line);
	if ((fd2 = open(file, O_RDONLY)) < 0 && !close(fd))
		return (NULL);
	if (!(map->map = (int **)malloc(sizeof(int *) * (map->line + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd2, &line) > 0)
	{
		map->map[i++] = ft_intsplitstr(line, " \t\n");
		free(line);
	}
	map->map[i] = NULL;
	close(fd2);
	return (map);
}
