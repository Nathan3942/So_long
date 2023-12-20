/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:01:17 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/20 18:07:29 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//fonction pour trouver un chemin valide
int	chemin(t_data *data)
{
	int	i;
	int	j;
	int	res;

	i = find_i(data->map, 'E');
	j = find_j(data->map, 'E');
	res = find_chemin(i, j, data);
	if (res == 1)
		return (1);
	else
		return (0);
}

//verifie tout les chemin possible pour voir si la map est fesable
int	find_chemin(int i, int j, t_data *data)
{
	int	res;

	if (data->map[i][j] == 'P')
		return (1);
	if (i <= 0 || j <= 0 || i >= data->mapj || j >= data->mapi
		|| data->map[i][j] == '1' || data->mapbis[i][j] == '1')
		return (0);
	data->mapbis[i][j] = '1';
	res = (find_chemin(i - 1, j, data) || find_chemin(i + 1, j, data)
			|| find_chemin(i, j - 1, data) || find_chemin(i, j + 1, data));
	return (res);
}

//initialise une copie de la map
void	copymap(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->mapbis = (char **)malloc((data->mapj + 1) * sizeof(char *));
	while (data->map[j])
	{
		i = 0;
		data->mapbis[j] = (char *)malloc ((data->mapi + 1) * sizeof(char));
		while (data->map[j][i])
		{
			data->mapbis[j][i] = data->map[j][i];
			i++;
		}
		j++;
	}
}
