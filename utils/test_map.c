/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:29:31 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/19 19:56:46 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//verifie que toutes les ligne font la mm taille 
static int	test_1(char **map, int j, int *i)
{
	*i = 0;
	while (map[*i])
	{
		if (j != ft_strlen(map[*i]))
			return (0);
		*i += 1;
	}
	return (1);
}

//verifie si le haut et le bas de la map sont bien des mur
static int	test_2(char **map, int i)
{
	int	j;

	j = 0;
	while (map[0][j] == '1' && map[i - 1][j] == '1')
		j++;
	return (j);
}

//verifie si les cote de la map sont ferme
static int	test_3(char **map, int j)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

//verifie si tout les caractere pour etre sur quil sont valide
static int	test_4(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
			&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//valide la map et verifie si les 3 element demande sont present
int	test_map(char **map)
{
	int	i;
	int	j;
	int	w;

	w = 0;
	if (!map)
		return (0);
	j = ft_strlen(map[0]);
	if (test_1(map, j, &i) == 0)
		return (0);
	if (test_2(map, i) != j)
		return (0);
	if (test_3(map, j) == 0)
		return (0);
	if (test_4(map) == 0)
		return (0);
	w = w + find_c(map, 'C');
	w = w + find_c(map, 'P');
	w = w + find_c(map, 'E');
	if (w != 3)
		return (0);
	return (1);
}
