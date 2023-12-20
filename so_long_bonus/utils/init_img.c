/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:52:59 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/20 18:38:55 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_nindice(char *c, char *v)
{
	*c = '0';
	*v = 'N';
}

int	init_random(void)
{
	return (rand() % 4);
}

void	init_rand(void)
{
	srand(time(NULL));
}

void	init_win(t_data *data)
{
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit.xpm",
			&data->hei, &data->wid);
	data->exit2 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit2.xpm",
			&data->hei, &data->wid);
	data->fond = mlx_xpm_file_to_image(data->mlx_ptr, "./img/fond2.xpm",
			&data->hei, &data->wid);
	data->herod1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herodroit.xpm",
			&data->hei, &data->wid);
	data->herod2 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herodroit2.xpm",
			&data->hei, &data->wid);
	data->herog1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herogauche.xpm",
			&data->hei, &data->wid);
	data->herog2 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herogauche2.xpm",
			&data->hei, &data->wid);
	data->herodos = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herodos.xpm",
			&data->hei, &data->wid);
	data->herodos2 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herodos2.xpm",
			&data->hei, &data->wid);
	data->herodos3 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herodos3.xpm",
			&data->hei, &data->wid);
	data->enemi = mlx_xpm_file_to_image(data->mlx_ptr, "./img/enemi.xpm",
			&data->hei, &data->wid);
	data->herb = mlx_xpm_file_to_image(data->mlx_ptr, "./img/herb.xpm",
			&data->hei, &data->wid);
}
