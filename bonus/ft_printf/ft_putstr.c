/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:09:29 by mbjaghou          #+#    #+#             */
/*   Updated: 2021/12/05 17:09:31 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *cp)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", cp);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], cp);
		i++;
	}
}
