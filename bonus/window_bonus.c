/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:28:58 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/02/21 19:52:48 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

void	mlx_fun(t_data data)
{
	init(&data);
	check_mostatela(data);
	check_lhyote(data);
	if (!check_content(&data, 0, 0))
	{
		ft_printf("Error\nProblem in the contents of the map");
		exit (0);
	}
	open_wind(&data);
	mlx_hook(data.mlx_win, 17, 0, destroy_window, &data);
	mlx_hook(data.mlx_win, 2, (1L << 0), key_hook, &data);
	mlx_loop(data.mlx);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len)
	{
		free (data->stock[i]);
		i++;
	}
	free (data->stock);
}

void	put_img(void *txt, int i, int j, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		txt, j * 64, i * 64);
}

void	draw(t_data *data, int i, int j)
{
	while (i < data->len)
	{	
		j = 0;
		while (j < data->wit)
		{
			if (data->stock[i][j] == '1')
				put_img(data->walls, i, j, data);
			else
			{
				put_img(data->lkhewa, i, j, data);
				if (data->stock[i][j] == 'P')
					put_img(data->spongbob, i, j, data);
				else if (data->stock[i][j] == 'C')
					put_img(data->kndil, i, j, data);
				else if (data->stock[i][j] == 'E')
					put_img(data->ananas, i, j, data);
				else if (data->stock[i][j] == 'H')
					put_img(data->chafchone, i, j, data);
			}	
			j++;
		}	
		i++;
	}
	show_moves(data);
}

void	open_wind(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 64 * data->wit, \
		64 * data->len, "so_long");
	data->ananas = mlx_xpm_file_to_image(data->mlx, \
		"bonus/imag/ananas.xpm", &data->a, &data->b);
	data->kndil = mlx_xpm_file_to_image(data->mlx, \
		"bonus/imag/kndil.xpm", &data->a, &data->b);
	data->spongbob = mlx_xpm_file_to_image(data->mlx, \
		"bonus/imag/spongbob.xpm", &data->a, &data->b);
	data->walls = mlx_xpm_file_to_image(data->mlx, \
		"bonus/imag/walls.xpm", &data->a, &data->b);
	data->lkhewa = mlx_xpm_file_to_image(data->mlx, \
		"bonus/imag/lkhwa.xpm", &data->a, &data->b);
	data->chafchone = mlx_xpm_file_to_image(data->mlx, \
		"bonus/imag/chafchone.xpm", &data->a, &data->b);
	if (!data->walls || !data->spongbob || !data->kndil || !data->ananas \
		|| !data->lkhewa || !data->chafchone)
	{
		ft_printf("Error\nfor image");
		exit(0);
	}
	draw(data, 0, 0);
}
