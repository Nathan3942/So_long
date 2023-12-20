/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:10:14 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/20 18:56:01 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//ajoute les image dans la fenetre
void	map_put_photo(t_data *data, int nb)
{
	if (data->map[data->tb_i][data->tb_j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->herb, data->tb_y, data->tb_z);
	if (data->map[data->tb_i][data->tb_j] == '1')
	{
		if (nb % 2 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->wall, data->tb_y, data->tb_z);
		else if (nb % 3 == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->wall1, data->tb_y, data->tb_z);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->wall2, data->tb_y, data->tb_z);
	}
	if (data->map[data->tb_i][data->tb_j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collect, data->tb_y, data->tb_z);
	sprit_p(data);
	sprit_e(data);
	if (data->map[data->tb_i][data->tb_j] == 'N')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemi, data->tb_y, data->tb_z);
}

//place les element correctement par rapport a la map
int	render(t_data *data)
{
	int	nb;

	nb = 0;
	data->tb_i = 0;
	data->tb_z = -50;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->fond, 0, 0);
	while (data->map[data->tb_i])
	{
		data->tb_j = 0;
		data->tb_z = data->tb_z + 50;
		data->tb_y = 0;
		while (data->map[data->tb_i][data->tb_j])
		{
			map_put_photo(data, nb);
			data->tb_y = data->tb_y + 50;
			data->tb_j += 1;
			nb++;
		}
		data->tb_i += 1;
	}
	return (0);
}
