/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:43:10 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/06 15:54:54 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*wall;
	void	*collect;
	void	*hero;
	void	*exit;
	void	*fond;
	int		pos_i;
	int		pos_j;
	int		nbcollect;
	int		width;
	int		height;
	int		wid;
	int		hei;
	int		tb_i;
	int		tb_j;
	int		tb_y;
	int		tb_z;
}			t_data;

int		main(int argc, char **argv);
int		test_ber(char *argv);
char	*gnl(int fd, char *buffer);
void	init_data(t_data *data, int fd, char *buffer);

char	**export_map(int fd);

int		find_pj(char **map);
int		find_pi(char **map);
void	cal_colect(t_data *data);

size_t	ft_strlen(const char *str);
void	ft_putstr(char *str);
void	exit_map(void);

#endif