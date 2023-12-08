/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:40:30 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/08 15:41:25 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//trouve la position j de depart du joueur
int	find_pj(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

//trouve la position i de depart du joueur
int	find_pi(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

//compte le nombre de collectable et le met dans data->collect
void	cal_colect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->nbcollect = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->nbcollect += 1;
			j++;
		}
		i++;
	}
}

//verifie si le caractere passe en parametre est present dans la map
int	find_c(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	test_newline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}
