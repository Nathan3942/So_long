/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:35:40 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/06 17:09:40 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	void	*img;
}				t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	static int i = 300;
	static int x = 100;
	int z;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (keycode == 53)
		on_destroy(data);
	//data->img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/torti.xpm", &data->width, &data->height);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/champi.xpm", &data->width, &data->height);
	if (keycode == 2)
	{
		i += 50;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, i, x);
	}
	else if (keycode == 0)
	{
		i -= 50;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, i, x);
	}
	else if (keycode == 1)
	{
		x += 50;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, i, x);
	}
	else if (keycode == 13)
	{
		x -= 50;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, i, x);
	}
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1045, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	data.img = mlx_xpm_file_to_image(data.mlx_ptr, "./img/fond.xpm", &data.width, &data.height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);


	data.img = mlx_xpm_file_to_image(data.mlx_ptr, "./img/torti.xpm", &data.width, &data.height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 300, 100);


	// data.img = mlx_xpm_file_to_image(data.mlx_ptr, "./img/tiplouf.xpm", &data.width, &data.height);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 100);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
