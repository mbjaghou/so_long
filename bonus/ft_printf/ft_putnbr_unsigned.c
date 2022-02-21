/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:09:20 by mbjaghou          #+#    #+#             */
/*   Updated: 2021/12/05 17:09:22 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *cp)
{
	if (n < 10)
		ft_putchar(n + '0', cp);
	else
	{
		ft_putnbr(n / 10, cp);
		ft_putchar((n % 10) + 48, cp);
	}
}
