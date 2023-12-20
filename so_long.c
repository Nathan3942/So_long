/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:52:01 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/20 17:35:15 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verifie si le fichier est un .ber
int	test_ber(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (i < 5)
		return (0);
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e'
		|| argv[i - 3] != 'b' || argv[i - 4] != '.')
		return (0);
	return (1);
}

//lit le fichier ligne par ligne et met tout dans un buffer
char	*gnl(int fd, char *buffer)
{
	char	str;
	int		nbread;
	int		i;

	nbread = 1;
	i = 0;
	while (nbread != 0)
	{
		nbread = read(fd, &str, 1);
		if (nbread == -1)
			return (NULL);
		if (nbread != 0)
			buffer[i++] = str;
		buffer[i] = '\0';
	}
	if (i == 0)
		return (NULL);
	close(fd);
	return (buffer);
}

//initialise chaque element de la t_data
void	init_data(t_data *data, int fd, char *buffer)
{
	data->moves = 1;
	data->map = ft_split(gnl(fd, buffer), '\n', data);
	if (data->map == NULL)
		return ;
	copymap(data);
	data->pos_i = find_i(data->map, 'P');
	data->pos_j = find_j(data->map, 'P');
	cal_colect(data);
	data->tb_y = 0;
	data->tb_z = -50;
	data->tb_i = 0;
	data->tb_j = 0;
	data->mlx_ptr = mlx_init();
	data->width = 0;
	data->height = 0;
	while (data->map[data->height] != NULL)
		data->height++;
	data->height *= 50;
	data->width = ft_strlen(data->map[0]);
	data->width *= 50;
}

//initialise la fenetre et les fichier xpm en image
void	start_win(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "So_Long");
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./img/mur.xpm",
			&data->hei, &data->wid);
	data->hero = mlx_xpm_file_to_image(data->mlx_ptr, "./img/heroface.xpm",
			&data->hei, &data->wid);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, "./img/key.xpm",
			&data->hei, &data->wid);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit2.xpm",
			&data->hei, &data->wid);
	data->herb = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herb.xpm",
			&data->hei, &data->wid);
	data->fond = mlx_xpm_file_to_image(data->mlx_ptr, "./img/fond2.xpm",
			&data->hei, &data->wid);
}

//main argument 1 etant le fichier map
int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	char	buffer[9999];

	if (test_ber(argv[1]) == 0 || argc != 2)
		exit_map();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error fd\n");
		return (0);
	}
	init_data(&data, fd, buffer);
	if (test_map(data.map) == 0 || test_newline(buffer) == 0
		|| chemin(&data) == 0)
	{
		ft_putstr("Error\nIN MAPS\n");
		return (0);
	}
	start_win(&data);
	render(&data);
	mlx_hook(data.win_ptr, 2, 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_2, &data);
	mlx_loop(data.mlx_ptr);
}
