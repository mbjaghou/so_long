/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:13:54 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/02/21 19:57:06 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_data
{
	int		len;
	int		wit;
	char	**stock;
	int		col;
	int		player;
	int		p_x;
	int		p_y;
	int		collectible;
	int		exit;
	int		space;
	int		wall;
	int		drop;
	void	*spongbob;
	void	*kndil;
	void	*ananas;
	void	*walls;
	void	*chafchone;
	int		a;
	int		b;
	void	*mlx;
	void	*mlx_win;
	void	*lkhewa;
	int		moves;
	int		img_height;
	int		img_width;
	void	*texture_bird;

	void	*texture_black;
	int		steps;
}			t_data;

int		check_ext(char *map);
void	check_mostatela(t_data data);
void	check_lhyote(t_data data);
void	open_wind(t_data *data);
void	draw(t_data *data, int i, int j);
int		check_content(t_data *dita, int i, int j);
void	init(t_data *dita);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(t_data *data);
int		destroy_window(t_data *data);
int		key_hook(int key_code, t_data *data);
void	mlx_fun(t_data data);
void	show_moves(t_data *map);
#endif
