/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:04:58 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/20 18:43:38 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_3(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_putstr("YOU DIED\n");
	exit (0);
}

void	sprit_p(t_data *data)
{
	if (data->map[data->tb_i][data->tb_j] == 'P')
	{
		if (data->moves % 2 == 1 && data->direction == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->hero, data->tb_y, data->tb_z);
		else if (data->moves % 2 == 0 && data->direction == 0 &&
			data->moves % 4 != 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->heroface, data->tb_y, data->tb_z);
		else if (data->moves % 4 == 0 && data->direction == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->heroface2, data->tb_y, data->tb_z);
		if (data->moves % 2 == 0 && data->direction == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->herod1, data->tb_y, data->tb_z);
		else if (data->moves % 2 == 1 && data->direction == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->herod2, data->tb_y, data->tb_z);
		sprit_p1(data);
	}
}

void	sprit_p1(t_data *data)
{
	if (data->moves % 2 == 1 && data->direction == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->herog1, data->tb_y, data->tb_z);
	else if (data->moves % 2 == 0 && data->direction == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->herog2, data->tb_y, data->tb_z);
	if (data->moves % 2 == 1 && data->direction == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->herodos, data->tb_y, data->tb_z);
	else if (data->moves % 2 == 0 && data->direction == 3 &&
		data->moves % 4 != 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->herodos2, data->tb_y, data->tb_z);
	else if (data->moves % 4 == 0 && data->direction == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->herodos3, data->tb_y, data->tb_z);
}

void	sprit_e(t_data *data)
{
	if (data->nbcollect == 0)
	{
		if (data->map[data->tb_i][data->tb_j] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->exit2, data->tb_y, data->tb_z);
	}
	else
	{
		if (data->map[data->tb_i][data->tb_j] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->exit, data->tb_y, data->tb_z);
	}
}

void	moov_enemi(t_data *data, int nb)
{
	nb = init_random();
	if (nb == 0 && data->map[data->posn_i][data->posn_j - 1] == '0')
	{
		change_nindice(&(data->map[data->posn_i][data->posn_j]),
			&(data->map[data->posn_i][data->posn_j - 1]));
		data->posn_j -= 1;
	}
	if (nb == 1 && data->map[data->posn_i - 1][data->posn_j] == '0')
	{
		change_nindice(&(data->map[data->posn_i][data->posn_j]),
			&(data->map[data->posn_i - 1][data->posn_j]));
		data->posn_i -= 1;
	}
	if (nb == 2 && data->map[data->posn_i][data->posn_j + 1] == '0')
	{
		change_nindice(&(data->map[data->posn_i][data->posn_j]),
			&(data->map[data->posn_i][data->posn_j + 1]));
			data->posn_j += 1;
	}
	if (nb == 3 && data->map[data->posn_i + 1][data->posn_j] == '0')
	{
		change_nindice(&(data->map[data->posn_i][data->posn_j]),
			&(data->map[data->posn_i + 1][data->posn_j]));
		data->posn_i += 1;
	}
}
