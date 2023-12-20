/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:25:56 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/20 13:09:04 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//compte le nombre de ligne du fichier pour le 1er malloc (c = \n)
static int	bigstr(char const *str, char c, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (*str && *str == c)
		str++;
	while (str[i])
	{
		if ((str[i] == c && str[i + 1] != c) || (str[i + 1] == '\0'))
			j++;
		i++;
	}
	data->mapj = j;
	return (j);
}

//compte la taille d'une ligne pour le 2eme malloc
static int	smalstr(char const *str, char c, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	data->mapi = i;
	return (i);
}

//saute le \n de fin de ligne
static const char	*skip(const char *str, char c)
{
	while (str && *str == c)
		str++;
	return (str);
}

//free la map si le malloc echoue
static char	**ft_free(char **map)
{
	free(map);
	return (NULL);
}

//malloc la bonne taille de map pour la mettre dans data->map
char	**ft_split(char const *str, char c, t_data *data)
{
	char	**map;
	int		len;
	int		i;
	int		j;
	int		k;

	j = bigstr(str, c, data);
	i = 0;
	map = (char **)malloc((j + 1) * sizeof(char *));
	if (!map || !str)
		return (NULL);
	while (i < j)
	{
		str = skip(str, c);
		len = smalstr(str, c, data);
		map[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!map[i])
			return (ft_free(map));
		k = 0;
		while (k < len)
			map[i][k++] = *str++;
		map[i++][k] = '\0';
	}
	map[i] = NULL;
	return (map);
}
