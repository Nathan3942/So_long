/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_dir_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:25 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/08 16:57:18 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//gere la fin du programe avec la croix
int	exit_2(t_data *data)
{
	ft_putstr("you out\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

//test si le personnage peut aller sur la case suivante
void	test_right(t_data *data)
{
	if (data->map[data->pos_i][data->pos_j + 1] == 'E' && data->nbcollect == 0)
		exit_1(data, 0);
	else if (data->map[data->pos_i][data->pos_j + 1] != 'E')
		move_right(data);
}

void	test_down(t_data *data)
{
	if (data->map[data->pos_i + 1][data->pos_j] == 'E' && data->nbcollect == 0)
		exit_1(data, 0);
	else if (data->map[data->pos_i + 1][data->pos_j] != 'E')
		move_down(data);
}

void	test_left(t_data *data)
{
	if (data->map[data->pos_i][data->pos_j - 1] == 'E' && data->nbcollect == 0)
		exit_1(data, 0);
	else if (data->map[data->pos_i][data->pos_j - 1] != 'E')
		move_left(data);
}

void	test_up(t_data *data)
{
	if (data->map[data->pos_i - 1][data->pos_j] == 'E' && data->nbcollect == 0)
		exit_1(data, 0);
	else if (data->map[data->pos_i - 1][data->pos_j] != 'E')
		move_up(data);
}
