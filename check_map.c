/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:19:40 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/02/21 19:41:29 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

int	check_ext(char *map)
{
	int		i;
	char	*str;

	i = ft_strlen(map);
	str = map + i - 4;
	if (!ft_strncmp(str, ".ber", 4))
		return (1);
	else
		return (0);
}

void	check_mostatela(t_data data)
{
	int		n;
	int		i;
	int		v;

	n = 0;
	i = 0;
	v = 1;
	while (v <= data.len)
	{
		if (i == data.len - 1)
			n = ft_strlen(data.stock[i]);
		else
			n = ft_strlen(data.stock[i]) - 1;
		if (data.wit != n)
		{
			ft_printf("Error\nmap is not rectangle");
			exit(1);
		}
		v++;
		i++;
	}
}

void	check_lhyote(t_data data)
{
	int	i;

	i = 0;
	while (i < data.wit)
	{
		if (data.stock[0][i] != '1' || data.stock[data.len - 1][i] != '1')
		{
			ft_printf("Error\nprobleme fo walls");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data.len)
	{
		if (data.stock[i][0] != '1' || data.stock[i][data.wit - 1] != '1')
		{
			ft_printf("Error\nproblem for walls");
			exit(1);
		}
		i++;
	}
}

void	help(t_data *dita, int i, int j)
{
	if (dita->stock[i][j] == 'P')
	{
		dita->player++;
		dita->p_x = i;
		dita->p_y = j;
	}
	else if (dita->stock[i][j] == 'C')
		dita->collectible++;
	else if (dita->stock[i][j] == 'E')
		dita->exit++;
	else if (dita->stock[i][j] == '0')
		dita->space++;
	else if (dita->stock[i][j] == '1')
		dita->wall++;
	else
	{
		ft_printf("Error\nundefined character");
		exit (1);
	}
}

int	check_content(t_data *dita, int i, int j)
{
	while (i < dita->len)
	{
		j = 0;
		while (j < dita->wit)
		{
			help(dita, i, j);
			j++;
		}
		i++;
	}
	if (dita->collectible > 0 && dita->exit > 0 && dita->player == 1 \
		&& dita->space > 0 && dita->wall > 0)
		return (1);
	return (0);
}
