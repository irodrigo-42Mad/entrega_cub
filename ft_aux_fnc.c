/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fnc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:55:28 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/26 10:36:58 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_cub(char *line, int *pos)
{
	int	num;

	num = 0;
	ft_skip_spaces(line, pos);
	while (line[*pos] >= '0' && line[*pos] <= '9')
	{
		num = num * 10 + (line[*pos] - 48);
		(*pos)++;
	}
	return (num);
}

int	ft_prerequisites(t_game_draw *mygame)
{
	if (mygame->stat_txt.north == 1
		&& mygame->stat_txt.south == 1
		&& mygame->stat_txt.east == 1
		&& mygame->stat_txt.west == 1
		&& mygame->stat_txt.sprite == 1
		&& mygame->stat_txt.floor != RGB_NONE
		&& mygame->stat_txt.ceil != RGB_NONE)
		return (0);
	return (-1);
}

int	ft_parse_map(t_game_draw *mygame)
{
	if (ft_check_content(mygame) == -1)
		return (-1);
	if (ft_check_gamer(mygame) == -1)
		return (-1);
	if (ft_check_close(mygame) == -1)
		return (-1);
	return (1);
}

int	ft_take_width(char **str, int pos)
{
	int	col;
	int	len;

	col = 0;
	len = 0;
	while (str[pos][col] != '\0')
	{
		len++;
		col++;
	}
	return (len);
}

void	ft_set_mapchar(t_game_draw *mygame, int mat_pos, int line, int pos)
{
	if (mygame->mapchar[pos] == '3')
	{
		ft_setgamer(mygame, mat_pos, line);
	}
	mygame->worldmap[line][mat_pos] = mygame->mapchar[pos];
}
