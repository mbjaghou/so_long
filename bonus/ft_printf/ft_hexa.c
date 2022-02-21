/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:08:28 by mbjaghou          #+#    #+#             */
/*   Updated: 2021/12/05 17:08:33 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned int n, const char *base, int *cp)
{
	if (n < 16)
		ft_putchar(base[n], cp);
	else
	{
		ft_hexa(n / 16, base, cp);
		ft_putchar(base[n % 16], cp);
	}
}
