/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:43:10 by njeanbou          #+#    #+#             */
/*   Updated: 2023/12/08 17:02:26 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
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
	int		moves;
}			t_data;

int		main(int argc, char **argv);
int		test_ber(char *argv);
char	*gnl(int fd, char *buffer);
void	init_data(t_data *data, int fd, char *buffer);

int		exit_2(t_data *data);
void	test_right(t_data *data);
void	test_down(t_data *data);
void	test_left(t_data *data);
void	test_up(t_data *data);

void	exit_1(t_data *data, int keycode);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);

void	change_indice(char *c, char *v);
int		key_hook(int keycode, t_data *data);

void	map_put_photo(t_data *data);
int		render(t_data *data);

char	**ft_split(char const *str, char c);

int		find_pj(char **map);
int		find_pi(char **map);
void	cal_colect(t_data *data);
int		find_c(char **map, char c);
int		test_newline(char *buffer);

int		test_map(char **map);

int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	exit_map(void);

#endif