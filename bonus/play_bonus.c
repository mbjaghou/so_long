/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:21:42 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/02/21 16:27:12 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "ft_printf/ft_printf.h"

void	show_moves(t_data *map)
{
	char	str[10];

	sprintf(str, "%d", map->moves);
	map->texture_black = mlx_xpm_file_to_image(map->mlx, \
	"bonus/imag/just_black.xpm", &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	map->texture_black, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 2, 2, 0x625B03, "Moves: ");
	mlx_string_put(map->mlx, map->mlx_win, 70, 2, 0x625B03, str);
}

int	destroy_window(t_data *data)
{
	ft_free(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_printf("Closing the window!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_exit(t_data *map, int i)
{
	if (i == 0)
		printf ("You win!\n");
	else if (i == 1)
		printf ("You lose!\n");
	free (map->stock);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (EXIT_SUCCESS);
}

void	player_moves(t_data *data, int i, int j)
{
	if (data->stock[data->p_x + i][data->p_y + j] != '1')
	{
		if (data->stock[data->p_x + i][data->p_y + j] == 'C')
			data->collectible--;
		else if (data->stock[data->p_x + i][data->p_y + j] == 'E' \
				&& data->collectible == 0)
			ft_exit(data, 0);
		else if (data->stock[data->p_x + i][data->p_y + j] == 'E' \
				&& data->collectible != 0)
			return ;
		else if (data->stock[data->p_x + i][data->p_y + j] == 'H')
			ft_exit(data, 1);
		data->moves++;
		data->stock[data->p_x + i][data->p_y + j] = 'P';
		data->stock[data->p_x][data->p_y] = '0';
		data->p_x += i;
		data->p_y += j;
		ft_printf("Moves: %d\n", data->moves);
		draw(data, 0, 0);
	}
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC)
		destroy_window(data);
	else if (key_code == A)
		player_moves(data, 0, -1);
	else if (key_code == W)
		player_moves(data, -1, 0);
	else if (key_code == D)
		player_moves(data, 0, 1);
	else if (key_code == S)
		player_moves(data, 1, 0);
	return (0);
}
