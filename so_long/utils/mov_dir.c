/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:09:43 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/08 18:03:40 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//sortie du programe si esc ou victoire
void	exit_1(t_data *data, int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		ft_putstr("you ouut ech\n");
		exit (0);
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_putstr("you winn\n");
	exit (0);
}

//deplace le personnage et ecrit le nombre de mouvement 
void	move_right(t_data *data)
{
	ft_putstr("MOVES: ");
	ft_putnbr(data->moves++);
	ft_putstr("\n");
	if (data->map[data->pos_i][data->pos_j + 1] == 'C')
		data->nbcollect -= 1;
	change_indice(&(data->map[data->pos_i][data->pos_j]),
		&(data->map[data->pos_i][data->pos_j + 1]));
	data->pos_j += 1;
}

void	move_down(t_data *data)
{
	ft_putstr("MOVES: ");
	ft_putnbr(data->moves++);
	ft_putstr("\n");
	if (data->map[data->pos_i + 1][data->pos_j] == 'C')
		data->nbcollect -= 1;
	change_indice(&(data->map[data->pos_i][data->pos_j]),
		&(data->map[data->pos_i + 1][data->pos_j]));
	data->pos_i += 1;
}

void	move_left(t_data *data)
{
	ft_putstr("MOVES: ");
	ft_putnbr(data->moves++);
	ft_putstr("\n");
	if (data->map[data->pos_i][data->pos_j - 1] == 'C')
		data->nbcollect -= 1;
	change_indice(&(data->map[data->pos_i][data->pos_j]),
		&(data->map[data->pos_i][data->pos_j - 1]));
	data->pos_j -= 1;
}

void	move_up(t_data *data)
{
	ft_putstr("MOVES: ");
	ft_putnbr(data->moves++);
	ft_putstr("\n");
	if (data->map[data->pos_i - 1][data->pos_j] == 'C')
		data->nbcollect -= 1;
	change_indice(&(data->map[data->pos_i][data->pos_j]),
		&(data->map[data->pos_i - 1][data->pos_j]));
	data->pos_i -= 1;
}
